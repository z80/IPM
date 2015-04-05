
local pairs        = pairs
local setmetatable = setmetatable
local type         = type
local error        = error

module( "matrix" )


function Matrix()
    local t = {}
    local key, value
    for key, value in pairs( mtx ) do
        t[key] = value
    end
    return setmetatable( t, meta_mtx )
end


meta_mtx = {}

meta_mtx.__index = function ( t, key )
    if ( type( key ) == 'number' ) then
        if ( key > 0 ) and ( key <= t.sz ) then
            t.initialized = false
            return t.a[key]
        end
    elseif ( key == "size" ) then
        return y.sz
    end
    return nil
end

meta_mtx.__mul = function ( t, x )
    if ( x.a == nil ) then
        local n = #(x)
        local b = {}
        for i = 1, n do
            b[i] = 0
            for j = 1, n do
                b[i] = b[i] + t.a[i][j] * x[j]
            end
        end
        return b
    else
        local ny = #(t.a)
        local nx = #(x.a[1])
        local m = #(t.a[1])
        b = Matrix()
        b:resize( ny )
        for i = 1, ny do
            for j = 1, nx do
                b[i][j] = 0
                for k = 1, m do
                    b[i][j] = b[i][j] + t.a[i][k] * x.a[k][j]
                end
            end
        end
        return b
    end
end


mtx = {}


function mtx:resize( sz )
    self.sz = sz
    local i
    self.a = {}
    for i=1, self.sz do
        local j
        self.a[i] = {}
        for j = 1, self.sz do
            self.a[i][j] = 0.0
        end
    end
end







function mtx:init()
    self.alpha = {}
    local i
    for i = 1, self.sz do
        self.alpha[i] = {}
    end
    
    self.gamma = {}
    for i = 1, self.sz do
        self.gamma[i] = {}
    end
    
    -- Вычисляем вспомогательные матрицы.
    for i = 1, self.sz do
        self.alpha[i][i] = 1.0
    end
    
    for i = 1, self.sz do
        local j, k
        for j = 1, ( i - 1 ) do
            self.alpha[i][j] = self.a[i][j]
            for k = 1, ( j - 1 ) do
                self.alpha[i][j] = self.alpha[i][j] - self.alpha[i][k] * self.gamma[k][j]
            end
            if ( self.gamma[j][j] == 0 ) then
                error( "det = 0" )
            end
            self.alpha[i][j] = self.alpha[i][j] / self.gamma[j][j]
        end
        
        for j = i, self.sz do
            self.gamma[i][j] = self.a[i][j]
            for k = 1, ( i - 1 ) do
                self.gamma[i][j] = self.gamma[i][j] - self.alpha[i][k] * self.gamma[k][j]
            end
        end
    end
    
    self.initialized = true
end



function mtx:solve( b )
    if ( not self.initialized ) then
        self:init()
    end
    
    local y = {}
    local i, j
    for i = 1, self.sz do
        y[i] = b[i]
        for j = 1, ( i - 1 ) do
            y[i] = y[i] - y[j] * self.alpha[i][j]
        end
    end
    
    local x = {}
    local k
    for k = 1, self.sz do
        i = self.sz + 1 - k
        x[i] = y[i]
        for j = ( i + 1 ), self.sz do
            x[i] = x[i] - x[j] * self.gamma[i][j]
        end
        x[i] = x[i] / self.gamma[i][i]
    end
    
    return x
end


function mtx:inv()
    local m = Matrix()
    m:resize( self.sz )
    local b = {}
    for i = 1, self.sz do
        for j = 1, self.sz do
            b[j] = ( i ~= j ) and 0 or 1
        end
        local x = self:solve( b )
        for j = 1, self.sz do
            m[j][i] = x[j]
        end
    end
    return m
end

function mtx:transpose()
    local a = {}
    for i = 1, self.sz do
        a[i] = {}
        for j = 1, self.sz do
            a[i][j] = self.a[j][i]
        end
    end
    self.a = a
end








