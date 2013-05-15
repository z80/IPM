<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.1">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Mechanical" color="7" fill="1" visible="yes" active="yes"/>
<layer number="101" name="Gehäuse" color="7" fill="1" visible="yes" active="yes"/>
<layer number="102" name="Mittellin" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="no" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="frames">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="DINA4_L">
<frame x1="0" y1="0" x2="264.16" y2="180.34" columns="4" rows="4" layer="94" border-left="no" border-top="no" border-right="no" border-bottom="no"/>
</symbol>
<symbol name="DOCFIELD">
<wire x1="0" y1="0" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="87.63" y2="15.24" width="0.1016" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="71.12" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="0" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="87.63" y1="5.08" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="22.86" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="15.24" width="0.1016" layer="94"/>
<text x="1.27" y="1.27" size="2.54" layer="94" font="vector">Date:</text>
<text x="12.7" y="1.27" size="2.54" layer="94" font="vector">&gt;LAST_DATE_TIME</text>
<text x="72.39" y="1.27" size="2.54" layer="94" font="vector">Sheet:</text>
<text x="86.36" y="1.27" size="2.54" layer="94" font="vector">&gt;SHEET</text>
<text x="88.9" y="11.43" size="2.54" layer="94" font="vector">REV:</text>
<text x="1.27" y="19.05" size="2.54" layer="94" font="vector">TITLE:</text>
<text x="1.27" y="11.43" size="2.54" layer="94" font="vector">Document Number:</text>
<text x="17.78" y="19.05" size="2.54" layer="94" font="vector">&gt;DRAWING_NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="DINA4_L" prefix="FRAME" uservalue="yes">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A4, landscape with extra doc field</description>
<gates>
<gate name="G$1" symbol="DINA4_L" x="0" y="0"/>
<gate name="G$2" symbol="DOCFIELD" x="162.56" y="0" addlevel="must"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="my_components">
<packages>
<package name="DINKLE_DT-49-B01W-03">
<description>Barrier Style Terminal Blocks &lt;br&gt;
Manufacturer: Dinkle &lt;br&gt;
Rated voltage: 300V&lt;br&gt;
Rated current: &lt;br&gt;
&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;25A(Version B) &lt;br&gt;
&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;10A(Vers. D)</description>
<pad name="2" x="0" y="0" drill="1.8"/>
<pad name="1" x="-9.5" y="0" drill="1.8"/>
<pad name="3" x="9.5" y="0" drill="1.8"/>
<wire x1="15" y1="-5" x2="-15" y2="-5" width="0.2032" layer="21"/>
<wire x1="-15" y1="-5" x2="-15" y2="13" width="0.2032" layer="21"/>
<wire x1="15" y1="13" x2="15" y2="-5" width="0.2032" layer="21"/>
<wire x1="15" y1="13" x2="13.5" y2="13" width="0.2032" layer="21"/>
<text x="-12.87" y="-6.3" size="1.27" layer="25">&gt;NAME</text>
<text x="3.175" y="-6.35" size="1.27" layer="27">&gt;VALUE</text>
<wire x1="13.5" y1="13" x2="5.5" y2="13" width="0.2032" layer="21"/>
<wire x1="5.5" y1="13" x2="4" y2="13" width="0.2032" layer="21"/>
<wire x1="4" y1="13" x2="-4" y2="13" width="0.2032" layer="21"/>
<wire x1="-4" y1="13" x2="-5.5" y2="13" width="0.2032" layer="21"/>
<wire x1="-5.5" y1="13" x2="-13.5" y2="13" width="0.2032" layer="21"/>
<wire x1="-13.5" y1="13" x2="-15" y2="13" width="0.2032" layer="21"/>
<wire x1="-13.5" y1="13" x2="-13.5" y2="-3" width="0.2032" layer="21"/>
<wire x1="-13.5" y1="-3" x2="-5.5" y2="-3" width="0.2032" layer="21"/>
<wire x1="-5.5" y1="-3" x2="-5.5" y2="13" width="0.2032" layer="21"/>
<wire x1="-5.5" y1="13" x2="-4" y2="13" width="0.2032" layer="21"/>
<wire x1="-4" y1="13" x2="-4" y2="-3" width="0.2032" layer="21"/>
<wire x1="-4" y1="-3" x2="4" y2="-3" width="0.2032" layer="21"/>
<wire x1="4" y1="-3" x2="4" y2="13" width="0.2032" layer="21"/>
<wire x1="4" y1="13" x2="5.5" y2="13" width="0.2032" layer="21"/>
<wire x1="5.5" y1="13" x2="5.5" y2="-3" width="0.2032" layer="21"/>
<wire x1="5.5" y1="-3" x2="13.5" y2="-3" width="0.2032" layer="21"/>
<wire x1="13.5" y1="-3" x2="13.5" y2="13" width="0.2032" layer="21"/>
<circle x="-9.5" y="6" radius="3" width="0.2032" layer="21"/>
<wire x1="-8.68529375" y1="8.930228125" x2="-7.778984375" y2="8.5076125" width="0.2032" layer="21"/>
<wire x1="-11.221003125" y1="3.49238125" x2="-10.314696875" y2="3.0697625" width="0.2032" layer="21"/>
<wire x1="-11.221003125" y1="3.49238125" x2="-10.164459375" y2="5.75815" width="0.2032" layer="21"/>
<wire x1="-10.164459375" y1="5.75815" x2="-12.258625" y2="6.734678125" width="0.2032" layer="21"/>
<wire x1="-12.258625" y1="6.734678125" x2="-11.83600625" y2="7.640984375" width="0.2032" layer="21"/>
<wire x1="-11.83600625" y1="7.640984375" x2="-9.74184375" y2="6.664459375" width="0.2032" layer="21"/>
<wire x1="-9.74184375" y1="6.664459375" x2="-8.68529375" y2="8.930228125" width="0.2032" layer="21"/>
<wire x1="-10.314696875" y1="3.0697625" x2="-9.25815" y2="5.33553125" width="0.2032" layer="21"/>
<wire x1="-9.25815" y1="5.33553125" x2="-7.16398125" y2="4.35900625" width="0.2032" layer="21"/>
<wire x1="-7.16398125" y1="4.35900625" x2="-6.741365625" y2="5.2653125" width="0.2032" layer="21"/>
<wire x1="-6.741365625" y1="5.2653125" x2="-8.83553125" y2="6.24184375" width="0.2032" layer="21"/>
<wire x1="-8.83553125" y1="6.24184375" x2="-7.778984375" y2="8.5076125" width="0.2032" layer="21"/>
<circle x="0" y="6" radius="3" width="0.2032" layer="21"/>
<wire x1="-0.236621875" y1="9.03215625" x2="0.75956875" y2="8.945003125" width="0.2032" layer="21"/>
<wire x1="-0.75955625" y1="3.054990625" x2="0.2366375" y2="2.96783125" width="0.2032" layer="21"/>
<wire x1="-0.75955625" y1="3.054990625" x2="-0.541665625" y2="5.545475" width="0.2032" layer="21"/>
<wire x1="-0.541665625" y1="5.545475" x2="-2.84353125" y2="5.7468625" width="0.2032" layer="21"/>
<wire x1="-2.84353125" y1="5.7468625" x2="-2.756375" y2="6.74305625" width="0.2032" layer="21"/>
<wire x1="-2.756375" y1="6.74305625" x2="-0.4545125" y2="6.541671875" width="0.2032" layer="21"/>
<wire x1="-0.4545125" y1="6.541671875" x2="-0.236621875" y2="9.03215625" width="0.2032" layer="21"/>
<wire x1="0.2366375" y1="2.96783125" x2="0.454525" y2="5.45831875" width="0.2032" layer="21"/>
<wire x1="0.454525" y1="5.45831875" x2="2.756390625" y2="5.256934375" width="0.2032" layer="21"/>
<wire x1="2.756390625" y1="5.256934375" x2="2.84354375" y2="6.253125" width="0.2032" layer="21"/>
<wire x1="2.84354375" y1="6.253125" x2="0.541678125" y2="6.45451875" width="0.2032" layer="21"/>
<wire x1="0.541678125" y1="6.45451875" x2="0.75956875" y2="8.945003125" width="0.2032" layer="21"/>
<circle x="9.5" y="6" radius="3" width="0.2032" layer="21"/>
<wire x1="7.778996875" y1="8.507609375" x2="8.6853" y2="8.930228125" width="0.2032" layer="21"/>
<wire x1="10.31470625" y1="3.0697625" x2="11.221015625" y2="3.492378125" width="0.2032" layer="21"/>
<wire x1="10.31470625" y1="3.0697625" x2="9.258165625" y2="5.33553125" width="0.2032" layer="21"/>
<wire x1="9.258165625" y1="5.33553125" x2="7.163996875" y2="4.359003125" width="0.2032" layer="21"/>
<wire x1="7.163996875" y1="4.359003125" x2="6.741378125" y2="5.265309375" width="0.2032" layer="21"/>
<wire x1="6.741378125" y1="5.265309375" x2="8.83554375" y2="6.241840625" width="0.2032" layer="21"/>
<wire x1="8.83554375" y1="6.241840625" x2="7.778996875" y2="8.507609375" width="0.2032" layer="21"/>
<wire x1="11.221015625" y1="3.492378125" x2="10.16446875" y2="5.75815" width="0.2032" layer="21"/>
<wire x1="10.16446875" y1="5.75815" x2="12.258634375" y2="6.734675" width="0.2032" layer="21"/>
<wire x1="12.258634375" y1="6.734675" x2="11.836015625" y2="7.640978125" width="0.2032" layer="21"/>
<wire x1="11.836015625" y1="7.640978125" x2="9.74184375" y2="6.664459375" width="0.2032" layer="21"/>
<wire x1="9.74184375" y1="6.664459375" x2="8.6853" y2="8.930228125" width="0.2032" layer="21"/>
</package>
<package name="B2B-XH-AM">
<description>&lt;b&gt;B2B-XH-A(M)&lt;/b&gt;  Top entry type, 2.5 mm, 2 pin 1 row&lt;p&gt;</description>
<pad name="1" x="-1.25" y="0" drill="1" diameter="1.5"/>
<pad name="2" x="1.25" y="0" drill="1" diameter="1.5"/>
<text x="-3.35" y="3.55" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.5" y="-3.75" size="1.27" layer="27">&gt;VALUE</text>
<hole x="-2.85" y="2" drill="1.1"/>
<wire x1="3.7" y1="-2.35" x2="2.1" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="2.1" y1="-2.35" x2="-3.75" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="-3.75" y1="-2.35" x2="-3.75" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="-3.75" y1="-1.4" x2="-3.75" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="-3.75" y1="-0.85" x2="-3.75" y2="3.4" width="0.2032" layer="21"/>
<wire x1="3.7" y1="3.4" x2="-3.75" y2="3.4" width="0.2032" layer="21"/>
<hole x="-2.85" y="2" drill="1.1"/>
<wire x1="-2.1" y1="-2.3" x2="-2.1" y2="-2" width="0.127" layer="21"/>
<wire x1="-2.1" y1="-2" x2="2.1" y2="-2" width="0.127" layer="21"/>
<wire x1="2.1" y1="-2" x2="2.1" y2="-2.35" width="0.127" layer="21"/>
<wire x1="-3.75" y1="-0.85" x2="-3.5" y2="-0.85" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-0.85" x2="-3.5" y2="-1.4" width="0.127" layer="21"/>
<wire x1="-3.5" y1="-1.4" x2="-3.75" y2="-1.4" width="0.127" layer="21"/>
<wire x1="3.7" y1="-2.35" x2="3.7" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="3.7" y1="-1.4" x2="3.7" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="3.7" y1="-0.85" x2="3.7" y2="3.4" width="0.2032" layer="21"/>
<wire x1="3.7" y1="-0.85" x2="3.45" y2="-0.85" width="0.127" layer="21"/>
<wire x1="3.45" y1="-0.85" x2="3.45" y2="-1.4" width="0.127" layer="21"/>
<wire x1="3.45" y1="-1.4" x2="3.7" y2="-1.4" width="0.127" layer="21"/>
</package>
<package name="B3B-XH-AM">
<wire x1="5" y1="-2.35" x2="2.5" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="2.5" y1="-2.35" x2="-2.5" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="-2.5" y1="-2.35" x2="-5" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="5" y1="3.4" x2="-5" y2="3.4" width="0.2032" layer="21"/>
<pad name="1" x="-2.5" y="0" drill="1" diameter="1.5"/>
<pad name="2" x="0" y="0" drill="1" diameter="1.5"/>
<text x="-4.4" y="3.55" size="1.27" layer="25">&gt;NAME</text>
<text x="-4.6" y="-3.9" size="1.27" layer="27">&gt;VALUE</text>
<hole x="-4.1" y="2" drill="1.1"/>
<pad name="3" x="2.5" y="0" drill="1" diameter="1.5"/>
<wire x1="5" y1="-2.35" x2="2.5" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="2.5" y1="-2.35" x2="0.85" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="0.85" y1="-2.35" x2="-2.5" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="-2.5" y1="-2.35" x2="-5" y2="-2.35" width="0.2032" layer="21"/>
<wire x1="-5" y1="-2.35" x2="-5" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="-5" y1="-1.4" x2="-5" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="-5" y1="-0.85" x2="-5" y2="3.4" width="0.2032" layer="21"/>
<wire x1="-5" y1="-0.85" x2="-4.75" y2="-0.85" width="0.127" layer="21"/>
<wire x1="-4.75" y1="-0.85" x2="-4.75" y2="-1.4" width="0.127" layer="21"/>
<wire x1="-4.75" y1="-1.4" x2="-5" y2="-1.4" width="0.127" layer="21"/>
<wire x1="5" y1="-2.35" x2="5" y2="-1.4" width="0.2032" layer="21"/>
<wire x1="5" y1="-1.4" x2="5" y2="-0.85" width="0.2032" layer="21"/>
<wire x1="5" y1="-0.85" x2="5" y2="3.4" width="0.2032" layer="21"/>
<wire x1="5" y1="-0.85" x2="4.75" y2="-0.85" width="0.127" layer="21"/>
<wire x1="4.75" y1="-0.85" x2="4.75" y2="-1.4" width="0.127" layer="21"/>
<wire x1="4.75" y1="-1.4" x2="5" y2="-1.4" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-2.35" x2="-2.5" y2="-2" width="0.127" layer="21"/>
<wire x1="-2.5" y1="-2" x2="2.5" y2="-2" width="0.127" layer="21"/>
<wire x1="2.5" y1="-2" x2="2.5" y2="-2.35" width="0.127" layer="21"/>
</package>
<package name="MOLEX_09-65-2048">
<wire x1="8.02" y1="-5" x2="-8.02" y2="-5" width="0.2032" layer="21"/>
<wire x1="8.02" y1="5" x2="-8.02" y2="5" width="0.2032" layer="21"/>
<pad name="1" x="-5.94" y="0" drill="1.7" diameter="2.5"/>
<text x="-6.92" y="5.23" size="1.27" layer="25">&gt;NAME</text>
<text x="-6.925" y="-6.44" size="1.27" layer="27">&gt;VALUE</text>
<pad name="3" x="1.98" y="0" drill="1.7" diameter="2.5" rot="R90"/>
<wire x1="8.02" y1="-5" x2="-8.02" y2="-5" width="0.2032" layer="21"/>
<wire x1="-8.02" y1="-5" x2="-8.02" y2="-3" width="0.2032" layer="21"/>
<wire x1="-8.02" y1="-3" x2="-8.02" y2="5" width="0.2032" layer="21"/>
<wire x1="8.02" y1="-5" x2="8.02" y2="-3" width="0.2032" layer="21"/>
<pad name="4" x="5.94" y="0" drill="1.7" diameter="2.5"/>
<wire x1="8.02" y1="-3" x2="8.02" y2="5" width="0.2032" layer="21"/>
<wire x1="-8.02" y1="-3" x2="8.02" y2="-3" width="0.127" layer="21"/>
<pad name="2" x="-1.98" y="0" drill="1.7" diameter="2.5"/>
</package>
<package name="MOLEX_26-60-4050">
<wire x1="10" y1="-5" x2="-10" y2="-5" width="0.2032" layer="21"/>
<wire x1="10" y1="5" x2="-10" y2="5" width="0.2032" layer="21"/>
<pad name="1" x="-7.92" y="0" drill="1.7" diameter="2.5"/>
<text x="-6.92" y="5.23" size="1.27" layer="25">&gt;NAME</text>
<text x="-6.925" y="-6.44" size="1.27" layer="27">&gt;VALUE</text>
<pad name="3" x="0" y="0" drill="1.7" diameter="2.5" rot="R90"/>
<wire x1="10" y1="-5" x2="-10" y2="-5" width="0.2032" layer="21"/>
<wire x1="-10" y1="-5" x2="-10" y2="-3" width="0.2032" layer="21"/>
<wire x1="-10" y1="-3" x2="-10" y2="5" width="0.2032" layer="21"/>
<wire x1="10" y1="-5" x2="10" y2="-3" width="0.2032" layer="21"/>
<pad name="5" x="7.92" y="0" drill="1.7" diameter="2.5"/>
<wire x1="10" y1="-3" x2="10" y2="5" width="0.2032" layer="21"/>
<wire x1="-10" y1="-3" x2="10" y2="-3" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="M">
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="1.27" y2="0" width="0.6096" layer="94"/>
<text x="-0.508" y="1.016" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<pin name="S" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="MV">
<wire x1="1.27" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="1.27" y2="0" width="0.6096" layer="94"/>
<text x="-0.508" y="1.016" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<text x="-2.286" y="2.667" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="DINKLE_DT-49-B01W-03" prefix="X">
<description>Barrier Style Terminal Blocks &lt;br&gt;
Manufacturer: Dinkle &lt;br&gt;
Rated voltage: 300V&lt;br&gt;
Rated current: &lt;br&gt;
&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;25A(Version B) &lt;br&gt;
&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;&amp;nbsp;10A(Vers. D)</description>
<gates>
<gate name="-2" symbol="M" x="-5.08" y="0" addlevel="always"/>
<gate name="-3" symbol="M" x="-5.08" y="-5.08" addlevel="always"/>
<gate name="-1" symbol="MV" x="-5.08" y="5.08" addlevel="always"/>
</gates>
<devices>
<device name="" package="DINKLE_DT-49-B01W-03">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B2B-XH-A(M)" prefix="X">
<description>&lt;b&gt;B2B-XH-A(M)&lt;/b&gt;  Top entry type, 2.5 mm, 2 pin 1 row&lt;p&gt;</description>
<gates>
<gate name="-2" symbol="M" x="0" y="5.08" addlevel="always"/>
<gate name="-1" symbol="MV" x="0" y="7.62" addlevel="always"/>
</gates>
<devices>
<device name="" package="B2B-XH-AM">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="B3B-XH-A(M)" prefix="X">
<description>&lt;b&gt;B3B-XH-A(M)&lt;/b&gt;  Top entry type, 2.5 mm, 3 pins 1 row&lt;p&gt;</description>
<gates>
<gate name="-2" symbol="M" x="-5.08" y="0" addlevel="always"/>
<gate name="-3" symbol="M" x="-5.08" y="-2.54" addlevel="always"/>
<gate name="-1" symbol="MV" x="-5.08" y="2.54" addlevel="always"/>
</gates>
<devices>
<device name="" package="B3B-XH-AM">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MOLEX_09-65-2048" prefix="X">
<description>STECKER, 3.96MM KK, 
&lt;br&gt; 4KONTAKTE</description>
<gates>
<gate name="-1" symbol="MV" x="-5.08" y="0"/>
<gate name="-2" symbol="M" x="-5.08" y="-2.54"/>
<gate name="-3" symbol="M" x="-5.08" y="-5.08"/>
<gate name="-4" symbol="M" x="-5.08" y="-7.62"/>
</gates>
<devices>
<device name="" package="MOLEX_09-65-2048">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="MOLEX_26-60-4050" prefix="X">
<description>STECKER, 3.96MM KK, 
&lt;br&gt; 5KONTAKTE  (nur 3 von 5 im Einsatz)</description>
<gates>
<gate name="-1" symbol="MV" x="-5.08" y="2.54" addlevel="always"/>
<gate name="-3" symbol="M" x="-5.08" y="0" addlevel="always"/>
<gate name="-5" symbol="M" x="-5.08" y="-2.54" addlevel="always"/>
</gates>
<devices>
<device name="" package="MOLEX_26-60-4050">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-5" pin="S" pad="5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="holes">
<description>&lt;b&gt;Mounting Holes and Pads&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="2,8-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 2.8 mm, round</description>
<wire x1="0" y1="2.921" x2="0" y2="2.667" width="0.0508" layer="21"/>
<wire x1="0" y1="-2.667" x2="0" y2="-2.921" width="0.0508" layer="21"/>
<wire x1="-1.778" y1="0" x2="0" y2="-1.778" width="2.286" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="1.778" x2="1.778" y2="0" width="2.286" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.635" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="2.921" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="39"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="40"/>
<circle x="0" y="0" radius="3.175" width="0.8128" layer="43"/>
<circle x="0" y="0" radius="1.5" width="0.2032" layer="21"/>
<pad name="B2,8" x="0" y="0" drill="2.8" diameter="5.334"/>
</package>
<package name="3,0-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.0 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="39"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.6" width="0.2032" layer="21"/>
<pad name="B3,0" x="0" y="0" drill="3" diameter="5.842"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,0</text>
</package>
<package name="3,2-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.2 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.7" width="0.1524" layer="21"/>
<pad name="B3,2" x="0" y="0" drill="3.2" diameter="5.842"/>
<text x="-1.27" y="-3.81" size="1.27" layer="48">3,2</text>
</package>
<package name="3,3-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.3 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.27" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.7" width="0.2032" layer="21"/>
<pad name="B3,3" x="0" y="0" drill="3.3" diameter="5.842"/>
</package>
<package name="3,6-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 3.6 mm, round</description>
<wire x1="-2.159" y1="0" x2="0" y2="-2.159" width="2.4892" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.159" x2="2.159" y2="0" width="2.4892" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="3.429" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="3.683" width="1.397" layer="39"/>
<circle x="0" y="0" radius="3.683" width="1.397" layer="40"/>
<circle x="0" y="0" radius="3.556" width="1.016" layer="43"/>
<circle x="0" y="0" radius="1.9" width="0.2032" layer="21"/>
<pad name="B3,6" x="0" y="0" drill="3.6" diameter="5.842"/>
</package>
<package name="4,1-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.1 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="4.572" width="0.1524" layer="21"/>
<circle x="0" y="0" radius="5.08" width="2" layer="41"/>
<circle x="0" y="0" radius="5.08" width="2" layer="42"/>
<circle x="0" y="0" radius="5.08" width="2" layer="43"/>
<circle x="0" y="0" radius="2.15" width="0.2032" layer="21"/>
<pad name="B4,1" x="0" y="0" drill="4.1" diameter="8"/>
</package>
<package name="4,3-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.3 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.25" width="0.1524" layer="21"/>
<pad name="B4,3" x="0" y="0" drill="4.3" diameter="9"/>
</package>
<package name="4,5-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 4.5 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.35" width="0.1524" layer="21"/>
<pad name="B4,5" x="0" y="0" drill="4.5" diameter="9"/>
</package>
<package name="5,0-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 5.0 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.6" width="0.1524" layer="21"/>
<pad name="B5" x="0" y="0" drill="5" diameter="9"/>
</package>
<package name="5,5-PAD">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt; 5.5 mm, round</description>
<wire x1="-2.54" y1="0" x2="0" y2="-2.54" width="3.9116" layer="51" curve="90" cap="flat"/>
<wire x1="0" y1="2.54" x2="2.54" y2="0" width="3.9116" layer="51" curve="-90" cap="flat"/>
<circle x="0" y="0" radius="4.4958" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.762" width="0.4572" layer="51"/>
<circle x="0" y="0" radius="5.588" width="2" layer="43"/>
<circle x="0" y="0" radius="5.588" width="2" layer="42"/>
<circle x="0" y="0" radius="5.588" width="2" layer="41"/>
<circle x="0" y="0" radius="5.588" width="2" layer="39"/>
<circle x="0" y="0" radius="5.588" width="2" layer="40"/>
<circle x="0" y="0" radius="2.85" width="0.1524" layer="21"/>
<pad name="B5,5" x="0" y="0" drill="5.5" diameter="9"/>
</package>
</packages>
<symbols>
<symbol name="MOUNT-PAD">
<wire x1="0.254" y1="2.032" x2="2.032" y2="0.254" width="1.016" layer="94" curve="-75.749967" cap="flat"/>
<wire x1="-2.032" y1="0.254" x2="-0.254" y2="2.032" width="1.016" layer="94" curve="-75.749967" cap="flat"/>
<wire x1="-2.032" y1="-0.254" x2="-0.254" y2="-2.032" width="1.016" layer="94" curve="75.749967" cap="flat"/>
<wire x1="0.254" y1="-2.032" x2="2.032" y2="-0.254" width="1.016" layer="94" curve="75.749967" cap="flat"/>
<circle x="0" y="0" radius="1.524" width="0.0508" layer="94"/>
<text x="2.794" y="0.5842" size="1.778" layer="95">&gt;NAME</text>
<text x="2.794" y="-2.4638" size="1.778" layer="96">&gt;VALUE</text>
<pin name="MOUNT" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="MOUNT-PAD-ROUND" prefix="H">
<description>&lt;b&gt;MOUNTING PAD&lt;/b&gt;, round</description>
<gates>
<gate name="G$1" symbol="MOUNT-PAD" x="0" y="0"/>
</gates>
<devices>
<device name="2.8" package="2,8-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B2,8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.0" package="3,0-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,0"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.2" package="3,2-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.3" package="3,3-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="3.6" package="3,6-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B3,6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.1" package="4,1-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.3" package="4,3-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="4.5" package="4,5-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B4,5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.0" package="5,0-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="5.5" package="5,5-PAD">
<connects>
<connect gate="G$1" pin="MOUNT" pad="B5,5"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="FRAME1" library="frames" deviceset="DINA4_L" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="X3" library="my_components" deviceset="DINKLE_DT-49-B01W-03" device=""/>
<part name="X4" library="my_components" deviceset="DINKLE_DT-49-B01W-03" device=""/>
<part name="X1" library="my_components" deviceset="B2B-XH-A(M)" device=""/>
<part name="X2" library="my_components" deviceset="B2B-XH-A(M)" device=""/>
<part name="X5" library="my_components" deviceset="B3B-XH-A(M)" device=""/>
<part name="X6" library="my_components" deviceset="MOLEX_09-65-2048" device=""/>
<part name="X7" library="my_components" deviceset="MOLEX_26-60-4050" device=""/>
<part name="H1" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.3"/>
<part name="H2" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.3"/>
<part name="H3" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.3"/>
<part name="H4" library="holes" deviceset="MOUNT-PAD-ROUND" device="3.3"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0"/>
<instance part="FRAME1" gate="G$2" x="162.56" y="0"/>
<instance part="GND1" gate="1" x="101.6" y="147.32"/>
<instance part="GND2" gate="1" x="149.86" y="147.32"/>
<instance part="GND3" gate="1" x="149.86" y="99.06"/>
<instance part="X3" gate="-2" x="93.98" y="152.4"/>
<instance part="X3" gate="-3" x="93.98" y="154.94"/>
<instance part="X3" gate="-1" x="93.98" y="149.86" smashed="yes">
<attribute name="NAME" x="93.472" y="150.876" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="78.994" y="157.607" size="1.778" layer="96"/>
</instance>
<instance part="X4" gate="-2" x="157.48" y="152.4" rot="MR0"/>
<instance part="X4" gate="-3" x="157.48" y="149.86" rot="MR0"/>
<instance part="X4" gate="-1" x="157.48" y="154.94" smashed="yes" rot="MR0">
<attribute name="NAME" x="157.988" y="155.956" size="1.778" layer="95" rot="MR180"/>
<attribute name="VALUE" x="172.466" y="162.687" size="1.778" layer="96" rot="MR0"/>
</instance>
<instance part="X1" gate="-2" x="157.48" y="68.58" rot="MR0"/>
<instance part="X1" gate="-1" x="157.48" y="71.12" rot="MR0"/>
<instance part="X2" gate="-2" x="157.48" y="50.8" rot="R180"/>
<instance part="X2" gate="-1" x="157.48" y="53.34" rot="MR0"/>
<instance part="X5" gate="-3" x="157.48" y="129.54" rot="MR0"/>
<instance part="X5" gate="-1" x="157.48" y="132.08" smashed="yes" rot="MR0">
<attribute name="NAME" x="157.988" y="133.096" size="1.778" layer="95" rot="MR180"/>
<attribute name="VALUE" x="167.386" y="134.747" size="1.778" layer="96" rot="MR0"/>
</instance>
<instance part="X6" gate="-1" x="93.98" y="73.66"/>
<instance part="X6" gate="-2" x="93.98" y="71.12"/>
<instance part="X6" gate="-3" x="93.98" y="68.58"/>
<instance part="X6" gate="-4" x="93.98" y="66.04"/>
<instance part="X7" gate="-1" x="157.48" y="101.6" smashed="yes" rot="MR0">
<attribute name="NAME" x="157.988" y="102.616" size="1.778" layer="95" rot="MR180"/>
<attribute name="VALUE" x="159.766" y="109.347" size="1.778" layer="96" rot="MR0"/>
</instance>
<instance part="X7" gate="-3" x="157.48" y="104.14" rot="MR0"/>
<instance part="X7" gate="-5" x="157.48" y="106.68" rot="MR0"/>
<instance part="H1" gate="G$1" x="27.94" y="48.26" smashed="yes">
<attribute name="NAME" x="30.734" y="48.8442" size="1.778" layer="95"/>
<attribute name="VALUE" x="30.734" y="45.7962" size="1.778" layer="96"/>
</instance>
<instance part="H2" gate="G$1" x="27.94" y="40.64"/>
<instance part="H3" gate="G$1" x="27.94" y="33.02"/>
<instance part="H4" gate="G$1" x="27.94" y="25.4"/>
</instances>
<busses>
</busses>
<nets>
<net name="ACL" class="0">
<segment>
<wire x1="119.38" y1="106.68" x2="119.38" y2="129.54" width="0.1524" layer="91"/>
<wire x1="119.38" y1="129.54" x2="119.38" y2="132.08" width="0.1524" layer="91"/>
<wire x1="119.38" y1="132.08" x2="119.38" y2="154.94" width="0.1524" layer="91"/>
<label x="106.68" y="154.94" size="1.778" layer="95"/>
<label x="142.24" y="132.08" size="1.778" layer="95"/>
<pinref part="X5" gate="-3" pin="S"/>
<wire x1="152.4" y1="129.54" x2="119.38" y2="129.54" width="0.1524" layer="91"/>
<junction x="119.38" y="129.54"/>
<pinref part="X3" gate="-3" pin="S"/>
<wire x1="119.38" y1="154.94" x2="99.06" y2="154.94" width="0.1524" layer="91"/>
<pinref part="X4" gate="-1" pin="S"/>
<wire x1="119.38" y1="154.94" x2="152.4" y2="154.94" width="0.1524" layer="91"/>
<junction x="119.38" y="154.94"/>
<pinref part="X7" gate="-5" pin="S"/>
<wire x1="119.38" y1="106.68" x2="152.4" y2="106.68" width="0.1524" layer="91"/>
</segment>
</net>
<net name="ACN" class="0">
<segment>
<wire x1="116.84" y1="152.4" x2="99.06" y2="152.4" width="0.1524" layer="91"/>
<wire x1="116.84" y1="152.4" x2="116.84" y2="132.08" width="0.1524" layer="91"/>
<wire x1="116.84" y1="132.08" x2="116.84" y2="129.54" width="0.1524" layer="91"/>
<wire x1="116.84" y1="129.54" x2="116.84" y2="104.14" width="0.1524" layer="91"/>
<wire x1="116.84" y1="104.14" x2="152.4" y2="104.14" width="0.1524" layer="91"/>
<pinref part="X3" gate="-2" pin="S"/>
<wire x1="116.84" y1="152.4" x2="152.4" y2="152.4" width="0.1524" layer="91"/>
<pinref part="X4" gate="-2" pin="S"/>
<junction x="116.84" y="152.4"/>
<label x="106.68" y="152.4" size="1.778" layer="95"/>
<label x="142.24" y="129.54" size="1.778" layer="95"/>
<pinref part="X5" gate="-1" pin="S"/>
<wire x1="152.4" y1="132.08" x2="116.84" y2="132.08" width="0.1524" layer="91"/>
<junction x="116.84" y="132.08"/>
<pinref part="X7" gate="-3" pin="S"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<wire x1="149.86" y1="149.86" x2="114.3" y2="149.86" width="0.1524" layer="91"/>
<wire x1="114.3" y1="149.86" x2="101.6" y2="149.86" width="0.1524" layer="91"/>
<wire x1="149.86" y1="101.6" x2="114.3" y2="101.6" width="0.1524" layer="91"/>
<wire x1="114.3" y1="101.6" x2="114.3" y2="149.86" width="0.1524" layer="91"/>
<junction x="114.3" y="149.86"/>
<pinref part="GND1" gate="1" pin="GND"/>
<pinref part="GND2" gate="1" pin="GND"/>
<pinref part="GND3" gate="1" pin="GND"/>
<pinref part="X4" gate="-3" pin="S"/>
<wire x1="152.4" y1="149.86" x2="149.86" y2="149.86" width="0.1524" layer="91"/>
<pinref part="X3" gate="-1" pin="S"/>
<wire x1="101.6" y1="149.86" x2="99.06" y2="149.86" width="0.1524" layer="91"/>
<junction x="149.86" y="149.86"/>
<pinref part="X7" gate="-1" pin="S"/>
<wire x1="149.86" y1="101.6" x2="152.4" y2="101.6" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+19V" class="0">
<segment>
<wire x1="99.06" y1="71.12" x2="111.76" y2="71.12" width="0.1524" layer="91"/>
<wire x1="111.76" y1="71.12" x2="142.24" y2="71.12" width="0.1524" layer="91"/>
<wire x1="142.24" y1="71.12" x2="152.4" y2="71.12" width="0.1524" layer="91"/>
<wire x1="99.06" y1="73.66" x2="111.76" y2="73.66" width="0.1524" layer="91"/>
<wire x1="111.76" y1="73.66" x2="111.76" y2="71.12" width="0.1524" layer="91"/>
<junction x="111.76" y="71.12"/>
<wire x1="152.4" y1="53.34" x2="142.24" y2="53.34" width="0.1524" layer="91"/>
<wire x1="142.24" y1="53.34" x2="142.24" y2="71.12" width="0.1524" layer="91"/>
<junction x="142.24" y="71.12"/>
<pinref part="X1" gate="-1" pin="S"/>
<pinref part="X2" gate="-1" pin="S"/>
<pinref part="X6" gate="-1" pin="S"/>
<junction x="99.06" y="73.66"/>
<pinref part="X6" gate="-2" pin="S"/>
<junction x="99.06" y="71.12"/>
<label x="121.92" y="71.12" size="1.778" layer="95"/>
</segment>
</net>
<net name="0V" class="0">
<segment>
<wire x1="99.06" y1="68.58" x2="111.76" y2="68.58" width="0.1524" layer="91"/>
<wire x1="111.76" y1="68.58" x2="111.76" y2="66.04" width="0.1524" layer="91"/>
<wire x1="111.76" y1="66.04" x2="99.06" y2="66.04" width="0.1524" layer="91"/>
<wire x1="111.76" y1="68.58" x2="139.7" y2="68.58" width="0.1524" layer="91"/>
<junction x="111.76" y="68.58"/>
<wire x1="139.7" y1="68.58" x2="152.4" y2="68.58" width="0.1524" layer="91"/>
<wire x1="139.7" y1="68.58" x2="139.7" y2="50.8" width="0.1524" layer="91"/>
<wire x1="139.7" y1="50.8" x2="152.4" y2="50.8" width="0.1524" layer="91"/>
<junction x="139.7" y="68.58"/>
<pinref part="X1" gate="-2" pin="S"/>
<pinref part="X2" gate="-2" pin="S"/>
<pinref part="X6" gate="-3" pin="S"/>
<junction x="99.06" y="68.58"/>
<pinref part="X6" gate="-4" pin="S"/>
<junction x="99.06" y="66.04"/>
<label x="121.92" y="66.04" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
