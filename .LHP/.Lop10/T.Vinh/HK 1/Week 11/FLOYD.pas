const
  InputFile  = 'MINPATH.INP';
  OutputFile = 'MINPATH.OUT';
  max = 1000;
  maxEC = 1000;
  maxC = max * maxEC;
var
  c: array[1..max, 1..max] of Integer;
  Trace: array[1..max, 1..max] of Integer;	
  n, s, f: Integer;

procedure LoadGraph;		
var
  i, m, u, v: Integer;
  fi: Text;
begin
  Assign(fi, InputFile); Reset(fi);
  ReadLn(fi, n, m, s, f);
  for u := 1 to n do
    for v := 1 to n do
      if u = v then c[u, v] := 0 else c[u, v] := maxC;
  for i := 1 to m do ReadLn(fi, u, v, c[u, v]);
  Close(fi);
end;

procedure Floyd;
var
  k, u, v: Integer;
begin
  for u := 1 to n do
    for v := 1 to n do Trace[u, v] := v;	
  for k := 1 to n do
    for u := 1 to n do
      for v := 1 to n do
        if c[u, v] > c[u, k] + c[k, v] then
          begin
            c[u, v] := c[u, k] + c[k, v];
            Trace[u, v] := Trace[u, k];
          end;
end;

procedure PrintResult;
var
  fo: Text;
begin
  Assign(fo, OutputFile); Rewrite(fo);
  if c[s, f] = maxC
    then WriteLn(fo, 'There is no path from ', s, ' to ', f)
  else
    begin
      WriteLn(fo, 'Distance from ', s, ' to ', f, ': ', c[s, f]);
      repeat
        Write(fo, s, '->');
        s := Trace[s, f];
      until s = f;
      WriteLn(fo, f);
    end;
  Close(fo);
end;

begin
  LoadGraph;
  Floyd;
  PrintResult;
end.
