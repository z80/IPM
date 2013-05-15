
require( "unclasslib" )

Rf = class()

function Rf:__init()
    self.sleepTime = 0.5                              --Частота проверки состояния джойстиков

    self.dbetaMaxPerSecond = 10 * math.pi / 180       --Максимальные изменения параметров за секунду
    self.dalpha1MaxPerSecond = 10 * math.pi / 180
    self.dalpha2MaxPerSecond = 10 * math.pi / 180
    self.dl1MaxPerSecond = 15
    self.decMaxPerSecond = 10                        --Максимальное изменение декартовой координаты за секунду

    self.dbetaMax = dbetaMaxPerSecond * sleepTime     --Максимальные изменения параметров за иттерацию
    self.dalpha1Max = dalpha1MaxPerSecond * sleepTime
    self.dalpha2Max = dalpha2MaxPerSecond * sleepTime
    self.dl1Max = dl1MaxPerSecond * sleepTime
    self.decMax = decMaxPerSecond * sleepTime


    self.li = 100                            --Нижняя граница l1
    self.lt = 200                            --Верхняя граница l1
    self.l2 = 10                             --Длина плеча l2
end


function Rf:sleep( t )
    t = t or 1
    t = t * 1000
    for i = 1, t do
        msleep( 1 )
    end
end

function Rf:get_power_dl1( length )                       --Получение мощности в процентах для мотора шарнира l1
    return length / self.dl1Max * 100
end

function Rf:get_power_dbeta(angle)                      --Получение мощности в процентах для мотора шарнира beta
    return angle / self.dbetaMax * 100
end

function Rf:get_power_dalpha1(angle)                    --Получение мощности в процентах для мотора шарнира alpha1
    return angle / self.dalpha1Max * 100
end

function Rf:get_power_dalpha2(angle)                    --Получение мощности в процентах для мотора шарнира alpha2
    return angle / self.dalpha2Max * 100
end

function Rf:change_l1(length, power)                       --Изменить параметр шарнира l1
    return length + self.dl1Max * power / 100
end

function Rf:change_beta(angle, power)                      --Изменить параметр шарнира beta
    return angle + self.dbetaMax * power / 100
end

function Rf:change_alpha1(angle, power)                    --Изменить параметр шарнира alpha1
    return angle + self.dalpha1Max * power / 100
end

function Rf:change_alpha2(angle, power)                    --Изменить параметр шарнира alpha2
    return angle + self.dalpha2Max * power / 100
end

function Rf:dec_from_gen(b, a1, a2, length1)               --Получение декартовых координат конечной точки манипулятора через обобщенные
    local x = (length1 * math.cos(a1) + self.l2 * math.cos(a1 + a2)) * math.cos(b)
    local y = (length1 * math.cos(a1) + self.l2 * math.cos(a1 + a2)) * math.sin(b)
    local z = length1 * math.sin(a1) + self.l2 * math.sin(a1 + a2)
    return x, y, z
end

function Rf:parallel_gen_from_dec(x, y, z)                 --Получение обобщенных координат через декартовые в паралелльной задаче
    local b = math.atan(y/x)
    local length1 = math.sqrt(x * x + y * y + math.pow(z + self.l2, 2))
    local a1 = math.acos(math.sqrt((x * x + y * y)/(x * x + y * y + math.pow(z + self.l2, 2))))
    local a2 = -math.pi / 2 - math.acos(math.sqrt((x * x + y * y) / (x * x + y * y + math.pow(z + self.l2, 2))))
    return b, a1, a2, length1
end

function Rf:orthogonal_gen_from_dec(x, y, z)               --Получение обобщенных координат через декартовые в перпендикулярной задаче
    local b
    if y/x > 0 then b = math.atan(y/x) else b = math.atan(y/x) + math.pi end
    local length1 = math.sqrt(x * x + y * y + z * z + self.l2 * self.l2 - 2 * l2 * math.sqrt(x * x + y * y))
    local temp = (-self.l2 + math.sqrt(x * x + y * y)) / length1
    local a1 
    if temp <= 1 then 
        a1 = math.acos((-self.l2 + math.sqrt(x * x + y * y)) / length1)
        if z < 0 then a1 = -1 * a1 end
        else a1 = 0 end
    local a2 = -a1
    return b, a1, a2, length1
end

function Rf:orthogonal_gen_speed(dx, dy, dz, beta, alpha1, alpha2, l1) --Получение обобщенных скоростей
    local dbeta = (dy * math.cos(beta) - dx * math.sin(beta))/(l1 * math.cos(alpha1) + self.l2)
    local dalpha1 = -((dx * math.cos(beta) + dy * math.sin(beta)) * math.sin(alpha1) + dz * math.cos(alpha1))/ l1
    local dalpha2 = dalpha1
    local dl1 = (dx * math.cos(beta) + dy * math.sin(beta)) * math.cos(alpha1) + dz * math.sin(alpha1)
    return dbeta, dalpha1, dalpha2, dl1
end

function Rf:check_if_b_boundary(angle)                 --Проверка на концевую точку и возвращение допустимого изменения координаты beta
    if angle > 0 and angle < (2 * math.pi) then 
        return 0
    else
        if angle <= 0 then
            return 0 - angle
        end
        if angle >= (2 * math.pi) then
            return (2 * math.pi) - angle
        end
    end
end

function Rf:check_if_a1_boundary(angle)                --Проверка на концевую точку и возвращение допустимого изменения координаты alpha
    if angle > 0 and angle < (math.pi / 2) then 
        return 0
    else
        if angle <= 0 then
            return 0 - angle
        end
        if angle >= (math.pi / 2) then
            return (math.pi / 2) - angle
        end
    end
end


function Rf:check_if_l1_boundary(length)               --Проверка на концевую точку и возвращение допустимого изменения координаты l1
    if length > self.li and length < self.lt then
        return 0
    else
        if length <= self.li then
            return self.li - length
        end
        if length >= self.lt then
            return length - self.lt
        end
    end
end

function Rf:lowest_percent(p1, p2, p3)                 --Нахождение наименьшего числа
    local p = p1
    if p2 < p then p = p2 end
    if p3 < p then p = p3 end
    return p
end

function Rf:check_dbeta(dbeta1, dbeta2)
    local dbeta = dbeta1 + dbeta2
    if math.abs(dbeta) <= self.dbetaMax then 
        return dbeta2
    else
        if dbeta > 0 then return self.dbetaMax - dbeta1 end
        if dbeta < 0 then return -self.dbetaMax - dbeta1 end
    end
end

function Rf:getPower(beta, alpha1, alpha2, l1, x_joy3, y_joy3, x_joy4, y_joy4)  --Получение значений мощностей двигателей и обобщенных скоростей
    local x1, y1, z1 = Rf:dec_from_gen(beta, alpha1, alpha2, l1)       --Узнаем текущие декартовые координаты
    local x2, y2, z2 = 0, 0, 0
    local beta_new, alpha1_new, alpha2_new, l1_new = beta, alpha1, alpha2, l1
    local vbeta, valpha1, valpha2, vl1 = 0, 0, 0, 0
    local dbeta, dalpha1, dalpha2, dl1 = 0, 0, 0, 0
    local power_dbeta, power_dalpha1, power_dalpha2, power_dl10 = 0, 0, 0, 0

    if x_joy3 ~= 0 or y_joy3 ~= 0 or y_joy4 ~= 0 then
        local dx, dy, dz, vx, vy, vz
        local percent_beta, percent_alpha, percent_l1
        
        dx = (x_joy3 / 100) * self.decMax                --Получаем предпологаемые перемещения за период опроса
        dy = - (y_joy3 / 100) * self.decMax
        dz = - (y_joy4 / 100) * self.decMax
        
        x2 = x1 + dx
        y2 = y1 + dy
        z2 = z1 + dz
        
        local beta_temp, alpha1_temp, alpha2_temp, l1_temp = self:orthogonal_gen_from_dec(x2, y2, z2)    --Узнаем предпологаемые обобщенные координаты после смещения на dx, dy, dz
        dbeta, dalpha1, dalpha2, dl1 = beta_temp - beta_new, alpha1_temp - alpha1_new, alpha2_temp - alpha2_new, l1_temp - l1_new       --Получаем изменения обобщенных координат
        
        --Проводится проверка на граничные значения обобщенных координат и относительное уменьшение всех перемещений, если потребуется
        if dbeta ~= 0 then percent_beta = (dbeta + self:check_if_b_boundary(beta_temp)) / dbeta
            else percent_beta = 1 end
        if dalpha1 ~= 0 then percent_alpha = (dalpha1 + self:check_if_a1_boundary(alpha1_temp)) / dalpha1
            else percent_alpha = 1 end
        if dl1 ~= 0 then percent_l1 = (dl1 + self:check_if_l1_boundary(l1_temp)) / dl1
            else percent_l1 = 1 end
        local percent = self:lowest_percent(percent_beta, percent_alpha, percent_l1)
        
        dbeta = percent * dbeta
        dalpha1 = percent * dalpha1
        dalpha2 = percent * dalpha2
        dl1 = percent * dl1
    end

    if x_joy4 ~= 0 then
        local dbeta_x_joy4 = -(x_joy4 / 100) * self.dbetaMax
        dbeta_x_joy4 = self:check_dbeta(dbeta, dbeta_x_joy4)
        local beta_temp = self:change_beta(beta_new, self:get_power_dbeta(dbeta_x_joy4))
        
        dbeta_x_joy4 = dbeta_x_joy4 + self:check_if_b_boundary(beta_temp)
        dbeta = dbeta + dbeta_x_joy4
    end
    
    power_dbeta = self:get_power_dbeta(dbeta)
    power_dalpha1 = self:get_power_dalpha1(dalpha1)
    power_dalpha2 = self:get_power_dalpha2(dalpha2)
    power_dl1 = self:get_power_dl1(dl1)
    
    vbeta, valpha1, valpha2, vl1 = dbeta / sleepTime, dalpha1 / sleepTime, dalpha2 / sleepTime, dl1 / sleepTime
    
    return power_dbeta, power_dalpha1, power_dalpha2, power_dl1, vbeta, valpha1, valpha2, vl1
end

function Rf:moveManipulator(beta, alpha1, alpha2, l1, power_dbeta, power_dalpha1, power_dalpha2, power_dl1)    --Перемещение конечной точки манипулятора при заданных мощностях
    local beta_new = self:change_beta(beta, power_dbeta)
    local alpha1_new = self:change_alpha1(alpha1, power_dalpha1)
    local alpha2_new = self:change_alpha2(alpha2, power_dalpha2)
    local l1_new = self:change_l1(l1, power_dl1)
    return beta_new, alpha1_new, alpha2_new, l1_new
end

function Rf:insensitivity(x, y)                    --Проверка на зоны нечувствительности
    if math.abs(x) < 5 then
        x = 0
    end
    if x < -100 then
        x = -100
    end
    if x > 100 then
        x = 100
    end
    if math.abs(y) < 5 then
        y = 0
    end
    if y < -100 then
        y = -100
    end
    if y > 100 then
        y = 100
    end
    return x, y
end

function Rf:main()
    local x0, y0, z0 = 0, 110, 0
    local beta, alpha1, alpha2, l1 = math.pi/2, 0, 0, 100   --Начальные значения обобщенных координат
    
    while true do
        self:sleep( sleepTime )
        for i = 1, 4 do
            local x, y = joy( i )
            x, y = self:insensitivity(x, y)
            print( string.format( "joy[%i]: %3.2f%%, %3.2f%%", i, x, y ) )
        end
        
        local x_joy3, y_joy3 = self:insensitivity( joy( 3 ) )    --Снятие показаний с 3-го джойстика с учетом зоны нечувствительности
        local x_joy4, y_joy4 = self:insensitivity( joy( 4 ) )    --Снятие показаний с 4-го джойстика с учетом зоны нечувствительности
        
        local vbeta, valpha1, valpha2, vl1 = 0, 0, 0, 0
        local power_dbeta, power_dalpha1, power_dalpha2, power_dl1 = 0, 0, 0, 0
        
        if x_joy3 ~= 0 or y_joy3 ~= 0 or x_joy4 or y_joy4 ~= 0 then --Если есть отклонения 3-го и 4-го джойстиков
            power_dbeta, power_dalpha1, power_dalpha2, power_dl1, vbeta, valpha1, valpha2, vl1 = Rf:getPower(beta, alpha1, alpha2, l1, x_joy3, y_joy3, x_joy4, y_joy4)             --Получение значений мощностей двигателей и обобщенных скоростей
            beta, alpha1, alpha2, l1 = Rf:moveManipulator(beta, alpha1, alpha2, l1, power_dbeta, power_dalpha1, power_dalpha2, power_dl1)          --Перемещение конечной точки манипулятора при заданных мощностях
        end
        
        x0, y0, z0 = Rf:dec_from_gen(beta, alpha1, alpha2, l1) --Положение конечной точки в ДСК, связянной с роботом
        
        print( string.format("beta: %3.2f, alpha1: %3.2f, alpha2: %3.2f, l1: %3.2f", beta * 180 / math.pi, alpha1 * 180 / math.pi, alpha2 * 180 / math.pi, l1))
        print( string.format("vbeta: %3.2f, valpha1: %3.2f, valpha2: %3.2f, vl1: %3.2f", vbeta * 180 / math.pi, valpha1 * 180 / math.pi, valpha2 * 180 / math.pi, vl1))
        print( string.format("x: %3.2f, y: %3.2f, z: %3.2f", x0, y0, z0))
        
        print( " " )
   end
end





--print( "client.lua loaded!!!" )
--main()



