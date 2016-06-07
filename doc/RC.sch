<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,800,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=RC.dat>
  <DataDisplay=RC.dpl>
  <OpenDisplay=1>
  <Script=RC.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Название>
  <FrameText1=Чертил:>
  <FrameText2=Дата:>
  <FrameText3=Версия:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 350 240 0 0 0 0>
  <GND * 1 150 260 0 0 0 0>
  <Eqn Eqn1 1 510 160 -31 17 0 0 "Cp=1000p" 1 "Rs=1k" 1 "yes" 0>
  <R R1 1 230 160 -26 15 0 0 "Rs" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <C C1 1 350 210 17 -26 0 1 "Cp" 1 "" 0 "neutral" 0>
  <.TR TR1 1 350 330 0 73 0 0 "lin" 1 "0" 1 "3 us" 1 "1001" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <.AC AC1 1 130 330 0 71 0 0 "log" 1 "1 Hz" 1 "1000 kHz" 1 "121" 1 "no" 0>
  <Vac V1 1 150 230 18 -26 0 1 "1 V" 1 "1000 kHz" 1 "0" 0 "0" 0>
</Components>
<Wires>
  <350 160 350 180 "" 0 0 0 "">
  <260 160 350 160 "out" 320 100 40 "">
  <150 160 150 200 "" 0 0 0 "">
  <150 160 200 160 "in" 210 100 25 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
