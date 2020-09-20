const
  InputFile  = 'BT1.INP';
  OutputFile = 'BT1.OUT';
  max = 1000;
  maxEC = 1000;
  maxC = max * maxEC;
var
  c: array[1..max, 1..max] of Integer;
  d: array[1..max] of Integer;
  n, s, f: Integer;

procedure LoadGraph;		
var
  i, m, u, v: Integer;
  fi: Text;
begin
  Assign(fi, InputFile); Reset(fi);
  ReadLn(fi, n, m, s);
  for u := 1 to n do
    for v := 1 to n do
      if u = v then c[u, v] := 0 else c[u, v] := maxC;
  for i := 1 to m do ReadLn(fi, u, v, c[u, v]);
  Close(fi);
end;

procedure Init; 				
var
  i: Integer;
begin
  for i := 1 to n do d[i] := MaxC;
  d[s] := 0;
end;

procedure Ford_Bellman; 			
var
  Stop: Boolean;
  u, v, CountLoop: Integer;
begin
  for CountLoop := 1 to n - 1 do
    begin
      Stop := True;
      for u := 1 to n do
        for v := 1 to n do
          if d[v] > d[u] + c[u, v] then {Toi uu duong di (s,v)} 
            begin
              d[v] := d[u] + c[u, v];					
              Stop := False;
            end;
      if Stop then Break;
    end;

end;

procedure PrintResult;	
var
  fo: Text;
  i: integer;
begin
  Assign(fo, OutputFile); Rewrite(fo);
  for i:=1 to n do writeln(fo,d[i]);
  Close(fo);
end;

begin
  LoadGraph;
  Init;
  Ford_Bellman;
  PrintResult;
end.
