jQuery.fn.chiauc = function() {
var auc_request;
var $input = $(this);
$input.attr("autocomplete", "off");
var results = document.createElement("div");
var $results = $(results);
$results.hide().attr("id","auc_outer").css("width", $input.outerWidth()+"px");
var resultsdata = document.createElement("div");
var $resultsdata = $(resultsdata);
$('<div/>').attr("id","auc_inner").appendTo($results);
$resultsdata.attr("id","auc").appendTo($("#auc_inner", results));
$('<div/>').attr("id","auc_close").html('<a href="#">закрыть</a>').appendTo($("#auc_inner", results));
var $aucform = $input.parent("form");
$aucform.after($results);
var prev = "";
var resqty = 1;
var active = -1;
var lastKeyPressCode = null;
var minChars = 1;
var prevemptyvalue = new Array();

function IsInEmptyList(mystr) {
for (var i = 0; i < prevemptyvalue.length; i++) { if(prevemptyvalue[i]==mystr) return true; }
return false;
}
function AddEmptyList(mystr) {
if(!IsInEmptyList(mystr)) prevemptyvalue.push(mystr);
}

$input
.keydown(function(e) {
lastKeyPressCode = e.keyCode;
switch(e.keyCode) {
case 38: // up
	e.preventDefault();
	moveSelect(-1);
	break;
case 40: // down
	e.preventDefault();
	moveSelect(1);
	break;
case 13: 
	if($("a.ac_over", resultsdata).length ){
		$("<input/>").attr({"type" : "hidden", "name" : "auc", "value" : "1"}).appendTo($aucform);
		hideResultsNow();
	}
	break; 
default:
	active = -1;
	$input.stopTime("auc");
	$input.oneTime(400, "auc", function(){onChange();})
	break;
}
})
.blur(function() {
	hideResults();
});
function onChange() {
if( lastKeyPressCode == 46 || (lastKeyPressCode > 8 && lastKeyPressCode < 32) ) return hideResultsNow();
var v = $input.val();
if (v!=null) v = v.toLowerCase(); 
var processRequest = true;
if (v.length >= minChars && v!=prev && !IsInEmptyList(v)) {
	if (prev!="" && v.indexOf(prev)>=0) {
		if(resqty>0) {
			processRequest = true;
		}
		else {
			AddEmptyList(v);
			processRequest = false;
		}
	}
	else {
		processRequest = true;
	}
}
else {
	processRequest = false;
}
prev = v;
if (processRequest) {
	getDataFromServer(v);
} 
else {
	hideResultsNow();
}
};
function moveSelect(step) {
var lis = $("a", resultsdata);
if (!lis) return;
active += step;
if (active < 0) {
	active = 0;
} else if (active >= lis.size()) {
	active = lis.size() - 1;
}
lis.removeClass("ac_over");
$(lis[active]).addClass("ac_over");
$input.val($(lis[active]).text());
$input.focus();
};
function hideResults() {
$input.stopTime("auc");
$input.oneTime(300, "auc", function(){ hideResultsNow();});
};
function hideResultsNow() {
$input.stopTime("auc");
if ($results.is(":visible")) {$("a", resultsdata).removeClass("ac_over"); $results.hide();}
};
function getDataFromServer(sstr) {
var searchtmpl = $("input[name='tmpl']", $aucform).val();
if (searchtmpl!="results" &&  searchtmpl!="video" ) return;
var mylang = 'ru';
if(MyUrl(0).indexOf("english")>=0 || MyUrl(0).indexOf("/en/")>=0) mylang = 'en';
if(auc_request) {auc_request.abort();}
auc_request = $.ajax({
cache: true,
url: '/ajax/searchauc.ashx?tmpl='+searchtmpl+'&text='+encodeURIComponent(sstr)+'&lang='+mylang,
beforeSend: function(){
},
success: function(data){
if(data.length>0) {
	$resultsdata.html(data);
	resqty = 1;
	$("a","#auc_close").click( function() {hideResultsNow();});
	var aresults = $("a",$resultsdata);
	aresults.each(function() {
		var ttmp = $(this).html(); 
		if(ttmp.indexOf(sstr)==0) {
			$(this).html(ttmp.replace(sstr,"<b>"+sstr+"</b>"));
		}
		else {
			$(this).html(ttmp.replace(" "+sstr," <b>"+sstr+"</b>"));
		}
	});
	if ( aresults.size()<6 ) {$resultsdata.attr("style", "height:102px");} else {$resultsdata.removeAttr("style");}
	if ($.browser.msie && $.browser.version <= 6) {$("<iframe/>").height($results.height()).appendTo($results);} 
	aresults
	.hover(
	function() { aresults.removeClass("ac_over"); $(this).addClass("ac_over"); active = $.inArray($(this).get(0), aresults); },
	function() { $(this).removeClass("ac_over"); })
	.click( function() {
		$("<input/>").attr({"type" : "hidden", "name" : "auc", "value" : "1"}).appendTo($aucform);
		$input.val($(this).text()); $input.focus(); $aucform.submit(); return false;});
	$results.show();
}
else {
	AddEmptyList(sstr);
	resqty = 0;
	hideResults();
}
},
error: function() {resqty = 0; hideResults();}
});
};
return this;
};
/* AUC - END */

var VsLoad = false;
var VsLoaded = false;

function LoadRightMenuTitle(mtype,lang) {
var titlepfx = '';
if (lang=='en') {
titlepfx = (mtype=='video'?'Video on topics: ':(mtype=='lib'?'Documents on topics: ':'')); }
else {
titlepfx = (mtype=='video'?'Видеоролики по темам: ':(mtype=='lib'?'Документация по разделам: ':'')); }
if(typeof sitemenu == 'undefined') return;
for (var i = 0; i < 3; i++) {
var sitemenuelem = sitemenu[i];
if(typeof sitemenuelem.title == 'undefined') return;
$.each(sitemenuelem.name, function(index, value){$('a:contains('+value+')','#ml'+(i+1)*100).attr('title', titlepfx+sitemenuelem.title[index]+'...')}); }
}

function GoodsQty (TextQty, Lang) {
if (Lang=="en") {var reg=/товар[а-я]+/g; return TextQty.replace(reg,"goods");} else { return TextQty}
}

function MyUrl(urltype) {
return window.location.pathname+(urltype==1?window.location.search:'');}

function SetAuthNCart() {
var txt_user = "Пользователь"; var txt_cart = "Корзина"; var txt_rur = "руб."; var txt_acc = "Личный кабинет"; var txt_exit = "Выход"; var txt_login = "Логин"; var txt_pwd = "Пароль"; var txt_reg1 = "Зарегистрироваться"; var txt_reg2 = "Регистрация"; var txt_rem = "запомнить меня"; var txt_lang = "ru";
if(MyUrl(0).indexOf("english")>=0 || MyUrl(0).indexOf("/en/")>=0) {
txt_user = "User"; txt_cart = "My Cart"; txt_rur = "RuR."; txt_acc = "Your Account"; txt_exit = "Exit"; txt_login = "Login"; txt_pwd = "Password"; txt_reg1 = "Register"; txt_reg2 = "Register"; txt_reg2 = "Register"; txt_rem = "remember me"; txt_lang = "en";}
else { }
var bck = MyUrl(1);
var bck1 = (bck.indexOf("cart.aspx")==-1 && bck.indexOf("back_url")>=0) ? GetBackUrl(bck) : bck;
var bck2 = (bck.indexOf("order.aspx")>=0 || bck.indexOf("person.aspx")>=0 || bck.indexOf("det_invoice.aspx")>=0) ? '/' : bck;
if (typeof AuthNCart != 'undefined') {
$('#cartregion').html('<div class="case"><a href="/cart.aspx">'+txt_cart+'</a>: <span>'+AuthNCart.CartSumma+'</span> '+txt_rur+' ('+GoodsQty(AuthNCart.CartQty, txt_lang)+')</div>'); 
if (AuthNCart.UserName!='') {
$('#user').html('<span>'+txt_user+': '+ AuthNCart.UserName +'</span> <a href="/person.aspx">'+txt_acc+'</a> | <a href="/reg.aspx?tmpl=auth&amp;action=logoff&amp;back_url='+encodeURIComponent(bck2)+'">'+txt_exit+'</a>');}
else {
$('#user').html('<form action="/reg.aspx" method="post"><input type="hidden" name="tmpl" value="auth"><input type="hidden" name="action" value="login"><input type="hidden" name="back_url" value="'+bck1+'"><table id="tlform"><tr><td>'+txt_login+':</td><td><div><input name="uid" type="text" class="ctrl_b tf"></div></td><td class="pwdtxt">'+txt_pwd+':</td><td><div><input id="tpwd" name="pwd" type="password" class="ctrl_b tf"></div><div id="remember"><input type="checkbox" name="rem" class="ctrl_b"> '+txt_rem+'</div></td><td><div><input name="submit" type="submit" class="tlb" value="ok"></div></td><td><a href="/reg.aspx">'+txt_reg1+'</a></td></tr></table></form>');}
} 
else {
$('#cartregion').html('<a href="/cart.aspx">'+txt_cart+'</a>');
$('#user').html('<a href="/person.aspx">'+txt_reg2+' / '+txt_acc+'</a>');}
$('#remember').width($('#tpwd').outerWidth()-2);
$('#tpwd').attr("autocomplete", "off").focusin(function() {$(document).stopTime('mem');$('#remember').slideDown('fast');}).focusout(function() {$(document).oneTime(1000, 'mem', function(){$('#remember').slideUp('fast');});});
$('input','#remember').click(function(){$(document).stopTime('mem');});
}

function GetBackUrl(myurl) {
var bckurl = myurl.substr(myurl.indexOf('back_url=')+9);
return decodeURIComponent((bckurl.indexOf('&')>=0) ? bckurl.substr(0,bckurl.indexOf('&')) :  bckurl);
}

function SetCompareBtn () {
if (typeof AuthNCart != 'undefined') {
if (AuthNCart.CompareQty!='') {document.write('<a href="/compare.aspx?back_url='+encodeURIComponent(MyUrl(1))+'" title="Сравнить выбранные товары" class="cb btn-cmp">сравнить</a>');}
}}

function SetCompareBlock() {
if ($("#compare_block").size()>0 && typeof AuthNCart != 'undefined') {
if (AuthNCart.CompareQty!='') {
$("#compare_block").html('<div class="header1">Сравнение товаров</div><div class="infoarea">В вашем списке сравнения <br><b>'+ AuthNCart.CompareQty +'</b><br><br><a href="/compare.aspx?back_url='+encodeURIComponent(MyUrl(0))+'" title="Сравнить выбранные товары" class="cb btn-cmp">сравнить</a>&nbsp;&nbsp;&nbsp;<a href="/compare.aspx?back_url='+encodeURIComponent(MyUrl(0))+'&amp;clear=yes&amp;ret=yes" title="Очистить список сравнения" class="cb btn-clr">очистить</a>').show(); }
}}

function SetQtyInfoBlock() {
if ($("#shop_avail").size()>0 && typeof AuthNCart != 'undefined') {
if (AuthNCart.UserName=='') {
$("#shop_avail").html('<div class="header1">Наличие товара в магазинах</div><div class="modul">Вы можете узнать точное количество<br>товара в каждом магазине Чип и Дип<br><br>Для этого нужно <a href="/reg.aspx?back_url='+encodeURIComponent(MyUrl(0))+'">зарегистрироваться</a></div>').show();}
}}

function AnalogLinks() {
$("dfn","#goodscontainer").each(function() {
var itemid = $(this).attr("id").replace("a","");
$(this).wrap('<a href="/analog.aspx?itemid='+itemid+'" title="См. аналоги этой позиции" />'); });
}

function LoadMenu(i) {
if(typeof sitemenu == 'undefined') return;
var sitemenuelem = sitemenu[i-1];
var myprefix = sitemenuelem.prefix;
var htmlmenuelem = "";
for (var j = 0; j < sitemenuelem.name.length; j++) {
htmlmenuelem += '<a href="' + sitemenuelem.prefix + sitemenuelem.url[j] + '.aspx">' + sitemenuelem.name[j] + '</a>'; }
return htmlmenuelem;
}

function ShopQtySymbol(qty){
var isAuthUser = false;
if (typeof AuthNCart != 'undefined') {if (AuthNCart.UserName!='') isAuthUser = true;}
if(isAuthUser) {
return '<span>'+(qty>0 ? qty : '-')+'</span>';}
else {
return qty>0 ? '<span class="shop_y" title="Есть">+</span>' : '<span class="shop_n" title="Нет">-</span>';}
}

function VideoTitleCorrect() {
$('div.ivt','#slideshow').each(function() {
var mydiv = $(this);
var myheight = mydiv.innerHeight();
while (myheight>24) {
var mytitle = mydiv.html();
mytitle = mytitle.substr(0,mytitle.lastIndexOf(' '));
mydiv.html(mytitle+'...');
myheight = mydiv.innerHeight();}
});
}

function SetIbWidthIn(max_ib_w) {
var $ib = $('div.ib_t2');
if($ib.length>0) {
if($ib.width()>=max_ib_w) {
$('div.last_ib',$ib).show();} else {$('div.last_ib',$ib).hide();}}
var $ibem = $('#ib_empty');
if($ibem.length>0) {
if($ibem.offset().top<500) $ibem.height(40+(500-$ibem.offset().top));}
}

function SetIbWidth(max_ib_w, timeout) {
if(timeout>0) {
$(document).stopTime("ib");
$(document).oneTime(timeout, "ib", function() {SetIbWidthIn(max_ib_w)});}
else {SetIbWidthIn(max_ib_w);}}

function SetScrollerWidth() {
$(document).stopTime("scrollerwidth");
$(document).oneTime(150, "scrollerwidth", function() {
var ww = $(window).width();
if (ww<1055) $('#slideshow').width(505);
if (ww>=1055 && ww<1230) $('#slideshow').width(680);
if (ww>=1230) $('#slideshow').width(855);
});
}

/*  DOCUMENT READY */

$(document).ready(function(){
if ($("#slider").get(0)!=null && $(window).height() > $("body").height()){
var sl_height = $("#slider").height();
$("#slider").height($(window).height() - $("body").height() + sl_height);
}
SetAuthNCart();

$("#prdfrmbtn a").click(function() {
var thisbtn = $(this).attr("id");
if($("input[name='chk']:checked").size() > 0) {
$("input[name='chk']:checked").each(function(i) {
var itemid = $(this).val();
$("<input/>").attr({"type" : "hidden", "name" : "chk", "value" : itemid}).appendTo($("#prdfrm"));
var itemqty = $("#qty"+itemid).val();
if (isNaN(parseInt(itemqty)) || parseInt(itemqty) < 0) {itemqty = 1;} else {itemqty = parseInt(itemqty);}
$("<input/>").attr({"type" : "hidden", "name" : "qty"+itemid, "value" : itemqty}).appendTo($("#prdfrm"));
$("#prdfrm").attr("action", (thisbtn=='a2c_multi' ? "/cart.aspx" : "/compare.aspx"));});
$("#prdfrm").submit();}
else {
alert("Для добавления в "+(thisbtn=='a2c_multi' ? "корзину" : "список сравнения") +" сразу нескольких товаров их необходимо отметить!");}
return false;
});

$("input[name='searchtext']", "form[name='search_form']:first").chiauc();

$("form[name='search_form']").submit( function() {
var str= $(this).find("input[name='searchtext']").val(); 
var reg=/[^A-Za-zА-Яа-я0-9Ёё _+(),\.\-\/\?]+/g;
$(this).find("input[name='searchtext']").val(str.replace(reg, ""));
return true;
});

$("a","#search-select").click( function() {
var $ssel = $("a.act","#search-select");
var thisrel = $ssel.attr("rel");
$ssel.attr("href", thisrel).removeAttr("rel").removeClass("act");
var newrel = $(this).attr("href");
$(this).addClass("act").attr("rel", newrel).removeAttr("href");
var formtmpl = $(this).attr("id").replace("sel_","");
$("input[name='tmpl']", "#topsearch").val(formtmpl);
var stxt = $("input[type='text']", "#topsearch").val();
if (stxt!=null && stxt!="" && stxt.length>2) {
$("form", "#topsearch").submit();
}
return false;
});

$("a","#pgsizeform").click( function() {
var mypgsize = $(this).attr("rel");
$("input[name^='pgsize']", "#pgsizeform").val(mypgsize); 
$("#pgsizeform").submit();
return false;
});

$("form[name='a2c']").submit( function() {
var bck = MyUrl(1);
bck = bck.replace("?sop=1","");
$("<input/>").attr({"type" : "hidden", "name" : "back_url", "value" : bck}).appendTo($(this).get(0));
var myqty = $("input[name='Qty']", this).val();
if (isNaN(parseInt(myqty))|| parseInt(myqty) <= 0) {alert ("Проверьте правильность ввода количества позиции!"); return false;}
else {$("input[name='Qty']", this).val(parseInt(myqty)); return true;}
});

$("form.cmp_frm","#goodscontainer").submit( function() {
var bck = MyUrl(1);
$("<input/>").attr({"type" : "hidden", "name" : "back_url", "value" : bck}).appendTo($(this).get(0));
return true;
});

if(MyUrl(0).indexOf("product")>=0) {
$("<input/>").attr({"type" : "hidden", "name" : "back_url", "value" : MyUrl(0)}).appendTo("#compare");
$("b","#productctrls").wrap('<a class="wrap" href="#" />');
$("a.wrap","#productctrls").click(function (){$(this).parent("form").submit(); return false;});

VideoTitleCorrect();
$('td.scrolls','#scroll-btns').show();
$('#scroll-prev').addClass('noact').removeAttr('title');
SetScrollerWidth();
$(window).resize(SetScrollerWidth);

$('#slideshow').serialScroll({
items:'li',
prev:'#scroll-prev',
next:'#scroll-next',
offset:0,
start:0, 
duration:400,
exclude:4,
force:true,
stop:true,
lock:false,
cycle:false,
jump: false,
lazy: true,
onBefore:function( e, elem, $pane, $items, pos ){
	if (pos>0){$('#scroll-prev').removeClass('noact').attr('title','Предыдущее видео');} else {$('#scroll-prev').addClass('noact').removeAttr('title');};
	if (pos>3 && pos>=$items.length-5){$('#scroll-next').addClass('noact').removeAttr('title');} else {$('#scroll-next').removeClass('noact').attr('title','Следующее видео');};
	if(!VsLoaded && $items.length<7 && pos>=$items.length-5 && (typeof ProductItemId != 'undefined')&& (typeof ProductScrollerVideoId != 'undefined')) {
		VsLoad = true;
	}
},
onAfter:function() {
	if (VsLoad && !VsLoaded) {
	$.get('/ajax/videoscroller.ashx?itemid='+ProductItemId+'&bl='+ProductScrollerVideoId, function(data) {
	$('ul','#slideshow').append(data); VideoTitleCorrect();}); 
	VsLoaded = true;}
	}
});

$("select","#subsform").change(function(){$("input[name='expires_date']","#subsform").val($(this).val())});
if($("input[name='InventLocationId']","#subsform").size() == 0) {$(".dis","#subsform").attr("disabled", "disabled");}
$("#subsform").submit( function () {
if($("input[name='InventLocationId']:checked","#subsform").size() > 0) {return true;} else {alert("Для оформления подписки на поступление товара\nнеобходимо отметить хотя бы один магазин!"); return false;}
});

$pdfc = $('<div/>').attr('id', 'pdfpreview');
$("a.i_pdf[rel]", "#product_content").hover(
function() {
var $pdfa = $(this);
var src_q = $pdfa.attr('rel');
var a_l = $pdfa.offset().left;
var a_t = $pdfa.offset().top;
var a_w = $pdfa.outerWidth();
var w_st = $(window).scrollTop();
var $myimg =  $('<img/>').attr({'src':src_q,'border':'0','alt':''});
$pdfc.appendTo($pdfa);
$pdfc.html($myimg);
$($myimg).load(function() {
var c_h = $pdfc.height(); 
var c_t = a_t - c_h + 15 + (a_t-w_st>c_h ? 0 : (c_h - (a_t-w_st))); 
$pdfc.css({top: c_t + 'px',left: a_l + a_w + 0 + 'px'}); 
$pdfc.oneTime(600, "pdfp", function() {$pdfc.fadeIn('fast');}); 
});
var t_src  = $myimg.attr('src');
$myimg.attr('src', '');
$myimg.attr('src', t_src); },
function() {$pdfc.stopTime("pdfp"); $pdfc.hide(); $pdfc.remove();})
.click(function() {$pdfc.hide();return true; });
} /* product>=0 */

$("#md1,#md2,#md3,#md4,#md5,#md6,#md7,#md8").hover(
function() {	
var mdx = $(this);
var i = mdx.attr("id").substr(2,1);
$("h3:not(#md"+i+")", "#mm").find("a:first").removeClass("m123h m46h m5h m7h m8h");
$("h3:not(#md"+i+")", "#mm").find("#ax").remove(); 
mdx.stopTime("hide");
if(mdx.find("#ax").length==0) {
mdx.oneTime(450, "show", function() {
$("<div/>").attr({"class" : "anylinkcss", "id" : "ax"}).appendTo(mdx);
var mi = mdx.find("a:first");
var ax = mdx.find("#ax");
if(i==1 || i==2 || i==3) {mi.addClass("m123h");} 
if(i==4 || i==6 ) {mi.addClass("m46h");} 
if(i==5 || i==7 || i==8) {mi.addClass("m"+i+"h");} 
var left_a = 0;
if (i>0 && i<8) {left_a = mi.offset().left-1;}
if (i==8) {left_a = mi.offset().left-160;}
var top_a = mi.offset().top + 41;
ax.css("left",left_a+"px");
ax.css("top",top_a+"px");
$("<div/>").attr("class","s-free").html(LoadMenu(i)).appendTo(ax);
if ($.browser.msie && $.browser.version <= 6) {$("<iframe/>").height(ax.height()).appendTo(ax);}
ax.slideDown(100);
});}
}, 
function() {
var mdx_out = $(this);
mdx_out.stopTime("show");
mdx_out.oneTime(250, "hide", function() {
mdx_out.find("#ax").slideUp(100, function() {$(this).remove(); mdx_out.find("a:first").removeClass("m123h m46h m5h m7h m8h");});	
});
});

$("a.m123,a.m46,a.m5,a.m7,a.m8","#mm").click( function() {
$(this).parent().find("#ax").remove(); return true;
});

$("div#breadcrumb").find("div.ddmenu").hover(function() {
var bmx = $(this);
$("#bx").remove();
bmx.oneTime(250, "show2", function() {
var id = bmx.attr("id");
$("<div/>").attr({"class" : "anylinkcss1", "id" : "bx"}).appendTo(bmx);
var bx = $("#bx");
var left_a = bmx.offset().left-1;
var top_a = bmx.offset().top + 12;
bx.css("left",left_a+"px");
bx.css("top",top_a+"px");
$.ajax({
cache: true,
url: '/ajax/bcmenu.ashx?id='+id,
beforeSend: function(){
bx.oneTime(500, "loading", function(){
	bx.addClass("loading");
	bx.fadeIn("fast");
	});},
success: function(data){
bx.stopTime("loading");
bx.removeClass("loading");
$("<div/>").attr("class","s-free").html(data).appendTo(bx);
if ($.browser.msie && $.browser.version <= 6) {$("<iframe/>").height(bx.height()-5).appendTo(bx);}
bx.slideDown(150); },
error: function(data){
bx.stopTime("loading");
bx.removeClass("loading");}
});
})
}, function() {
$(this).stopTime("show2");
$("#bx").remove();});

$("select","#param").hover(function(){$("#bx").remove();},function(){});

if(MyUrl(0).indexOf("product")>=0 && (typeof ProductItemId != 'undefined')) {
$("#avlupdatebtn").click( function () {
$.ajax({
dataType: "script",
url: "/ajax/shopqty.ashx?itemid="+ProductItemId,
beforeSend: function(){
$("#avlupdatebtn").attr("disabled", "disabled");
$("#subs_ok").attr("disabled", "disabled");
$("#updtext").html("Обновление данных...");
$("td.qty","#avl").addClass("load");
$("#shopbeg","#avl").addClass("loading2");
},
success: function(data){
$("td.qty","#avl").removeClass("load");
$("#shopbeg","#avl").removeClass("loading2");
if (typeof ShopQty != 'undefined') {
$("td.qty", "#avl").each ( function(i) {
		var shopid = $(this).attr("id");
		$(this).html(ShopQtySymbol(ShopQty[shopid]));
		if(ShopQty[shopid] == 0) 
		{$("#sub_"+shopid).removeAttr("disabled", "disabled");}
		else {$("#sub_"+shopid).attr("disabled", "disabled");}
	});
}
$("#subs_ok").removeAttr("disabled", "disabled");
$("#updtext").html("Данные по магазинам актуализированы.");
$("#avltextdiv").oneTime(3000, function() {$("#avltextdiv").slideUp("slow");});
},
error: function(data){
$("#avlupdatebtn").removeAttr("disabled", "disabled");
$("#subs_ok").removeAttr("disabled", "disabled");
$("#updtext").html("Не удалось обновить данные.");
$("td.qty","#avl").removeClass("load");
$("#shopbeg","#avl").removeClass("loading2");
}
});
});
}

}); /* ready */

/**
 * jQuery.timers
 **/
jQuery.fn.extend({everyTime:function(interval,label,fn,times){return this.each(function(){jQuery.timer.add(this,interval,label,fn,times)})},oneTime:function(interval,label,fn){return this.each(function(){jQuery.timer.add(this,interval,label,fn,1)})},stopTime:function(label,fn){return this.each(function(){jQuery.timer.remove(this,label,fn)})}});
jQuery.extend({timer:{global:[],guid:1,dataKey:"jQuery.timer",regex:/^([0-9]+(?:\.[0-9]*)?)\s*(.*s)?$/,powers:{'ms':1,'cs':10,'ds':100,'s':1000,'das':10000,'hs':100000,'ks':1000000},timeParse:function(value){if(value==undefined||value==null)return null;var result=this.regex.exec(jQuery.trim(value.toString()));if(result[2]){var num=parseFloat(result[1]);var mult=this.powers[result[2]]||1;return num*mult}else{return value}},add:function(element,interval,label,fn,times){var counter=0;if(jQuery.isFunction(label)){if(!times)times=fn;fn=label;label=interval}interval=jQuery.timer.timeParse(interval);if(typeof interval!='number'||isNaN(interval)||interval<0)return;if(typeof times!='number'||isNaN(times)||times<0)times=0;times=times||0;var timers=jQuery.data(element,this.dataKey)||jQuery.data(element,this.dataKey,{});if(!timers[label])timers[label]={};fn.timerID=fn.timerID||this.guid++;var handler=function(){if((++counter>times&&times!==0)||fn.call(element,counter)===false)jQuery.timer.remove(element,label,fn)};handler.timerID=fn.timerID;if(!timers[label][fn.timerID])timers[label][fn.timerID]=window.setInterval(handler,interval);this.global.push(element)},remove:function(element,label,fn){var timers=jQuery.data(element,this.dataKey),ret;if(timers){if(!label){for(label in timers)this.remove(element,label,fn)}else if(timers[label]){if(fn){if(fn.timerID){window.clearInterval(timers[label][fn.timerID]);delete timers[label][fn.timerID]}}else{for(var fn in timers[label]){window.clearInterval(timers[label][fn]);delete timers[label][fn]}}for(ret in timers[label])break;if(!ret){ret=null;delete timers[label]}}for(ret in timers)break;if(!ret)jQuery.removeData(element,this.dataKey)}}}});
jQuery(window).bind("unload",function(){jQuery.each(jQuery.timer.global,function(index,item){jQuery.timer.remove(item)})});
/*
 * jQuery.ScrollTo - Easy element scrolling using jQuery
 * Copyright (c) 2007-2009 Ariel Flesler - aflesler(at)gmail(dot)com | http://flesler.blogspot.com
 */
;(function(c){var a=c.scrollTo=function(f,e,d){c(window).scrollTo(f,e,d)};a.defaults={axis:"xy",duration:parseFloat(c.fn.jquery)>=1.3?0:1};a.window=function(d){return c(window)._scrollable()};c.fn._scrollable=function(){return this.map(function(){var e=this,d=!e.nodeName||c.inArray(e.nodeName.toLowerCase(),["iframe","#document","html","body"])!=-1;if(!d){return e}var f=(e.contentWindow||e).document||e.ownerDocument||e;return c.browser.safari||f.compatMode=="BackCompat"?f.body:f.documentElement})};c.fn.scrollTo=function(f,e,d){if(typeof e=="object"){d=e;e=0}if(typeof d=="function"){d={onAfter:d}}if(f=="max"){f=9000000000}d=c.extend({},a.defaults,d);e=e||d.speed||d.duration;d.queue=d.queue&&d.axis.length>1;if(d.queue){e/=2}d.offset=b(d.offset);d.over=b(d.over);return this._scrollable().each(function(){var l=this,j=c(l),k=f,i,g={},m=j.is("html,body");switch(typeof k){case"number":case"string":if(/^([+-]=)?\d+(\.\d+)?(px|%)?$/.test(k)){k=b(k);break}k=c(k,this);case"object":if(k.is||k.style){i=(k=c(k)).offset()}}c.each(d.axis.split(""),function(q,r){var s=r=="x"?"Left":"Top",u=s.toLowerCase(),p="scroll"+s,o=l[p],n=a.max(l,r);if(i){g[p]=i[u]+(m?0:o-j.offset()[u]);if(d.margin){g[p]-=parseInt(k.css("margin"+s))||0;g[p]-=parseInt(k.css("border"+s+"Width"))||0}g[p]+=d.offset[u]||0;if(d.over[u]){g[p]+=k[r=="x"?"width":"height"]()*d.over[u]}}else{var t=k[u];g[p]=t.slice&&t.slice(-1)=="%"?parseFloat(t)/100*n:t}if(/^\d+$/.test(g[p])){g[p]=g[p]<=0?0:Math.min(g[p],n)}if(!q&&d.queue){if(o!=g[p]){h(d.onAfterFirst)}delete g[p]}});h(d.onAfter);function h(n){j.animate(g,e,d.easing,n&&function(){n.call(this,f,d)})}}).end()};a.max=function(j,i){var h=i=="x"?"Width":"Height",e="scroll"+h;if(!c(j).is("html,body")){return j[e]-c(j)[h.toLowerCase()]()}var g="client"+h,f=j.ownerDocument.documentElement,d=j.ownerDocument.body;return Math.max(f[e],d[e])-Math.min(f[g],d[g])};function b(d){return typeof d=="object"?d:{top:d,left:d}}})(jQuery);
/*
 * jQuery.SerialScroll - Animated scrolling of series
 * Copyright (c) 2007-2009 Ariel Flesler - aflesler(at)gmail(dot)com | http://flesler.blogspot.com
 */
;(function(a){var b=a.serialScroll=function(c){return a(window).serialScroll(c)};b.defaults={duration:1e3,axis:"x",event:"click",start:0,step:1,lock:!0,cycle:!0,constant:!0};a.fn.serialScroll=function(c){return this.each(function(){var t=a.extend({},b.defaults,c),s=t.event,i=t.step,r=t.lazy,e=t.target?this:document,u=a(t.target||this,e),p=u[0],m=t.items,h=t.start,g=t.interval,k=t.navigation,l;if(!r){m=d()}if(t.force){f({},h)}a(t.prev||[],e).bind(s,-i,q);a(t.next||[],e).bind(s,i,q);if(!p.ssbound){u.bind("prev.serialScroll",-i,q).bind("next.serialScroll",i,q).bind("goto.serialScroll",f)}if(g){u.bind("start.serialScroll",function(v){if(!g){o();g=!0;n()}}).bind("stop.serialScroll",function(){o();g=!1})}u.bind("notify.serialScroll",function(x,w){var v=j(w);if(v>-1){h=v}});p.ssbound=!0;if(t.jump){(r?u:d()).bind(s,function(v){f(v,j(v.target))})}if(k){k=a(k,e).bind(s,function(v){v.data=Math.round(d().length/k.length)*k.index(this);f(v,this)})}function q(v){v.data+=h;f(v,this)}function f(B,z){if(!isNaN(z)){B.data=z;z=p}var C=B.data,v,D=B.type,A=t.exclude?d().slice(0,-t.exclude):d(),y=A.length,w=A[C],x=t.duration;if(D){B.preventDefault()}if(g){o();l=setTimeout(n,t.interval)}if(!w){v=C<0?0:y-1;if(h!=v){C=v}else{if(!t.cycle){return}else{C=y-v-1}}w=A[C]}if(!w||t.lock&&u.is(":animated")||D&&t.onBefore&&t.onBefore(B,w,u,d(),C)===!1){return}if(t.stop){u.queue("fx",[]).stop()}if(t.constant){x=Math.abs(x/i*(h-C))}u.scrollTo(w,x,t).trigger("notify.serialScroll",[C])}function n(){u.trigger("next.serialScroll")}function o(){clearTimeout(l)}function d(){return a(m,p)}function j(w){if(!isNaN(w)){return w}var x=d(),v;while((v=x.index(w))==-1&&w!=p){w=w.parentNode}return v}})}})(jQuery);