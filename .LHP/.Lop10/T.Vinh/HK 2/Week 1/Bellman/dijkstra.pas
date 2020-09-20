{$MODE OBJFPC}
const
  InputFile  = 'MINPATH.INP';
  OutputFile = 'MINPATH.OUT';
  max = 1000; {So dinh toi da}
  maxEC = 1000; {Trong so toi da cua moi canh}
  maxC = max * maxEC; {Vo cung}
var
  c: array[1..max, 1..max] of Integer; {c[u,v] tuong ung trong so cung (u,v)}
  d: array[1..max] of Integer;
  Trace: array[1..max] of Integer;
  Free: array[1..max] of Boolean; {Free[u]=true <=> u co nhan tu do}
  n, s, f: Integer;

procedure LoadGraph; {Nhap do thi voi trong so cac cung khong am}			
var
  i, m, u, v: Integer;
  fi: Text;
begin
  Assign(fi, InputFile); Reset(fi);
  ReadLn(fi, n, m, s, f);
  {Khoi tao do thi ban dau}
  for u := 1 to n do
    for v := 1 to n do
      if u = v then c[u, v] := 0 else c[u, v] := maxC;
  {Doc vao do thi trong so cac cung}
  for i := 1 to m do ReadLn(fi, u, v, c[u, v]);
  Close(fi);
end;

procedure Init;	{Khoi tao}				
var
  i: Integer;
begin
  for i := 1 to n do d[i] := MaxC; {Khoi tao tat ca cac dinh co khoang cach vo cung}
  d[s] := 0;
  FillChar(Free, SizeOf(Free), True); {Khoi tao tat ca cac dinh deu tu do}
end;

procedure Dijkstra;		
var
  i, u, v: Integer;
  min: Integer;
begin
  repeat
    {Tim trong cac dinh co nhan tu do ra dinh u co d[u] nho nhat}
    u := 0; min := maxC;
    for i := 1 to n do
      if Free[i] and (d[i] < min) then
        begin
          min := d[i];
          u := i;
        end;
		
	{Thoat neu da chon toi dinh f hoac
	khong tim duoc dinh u thoa dieu kien: u co nhan tu do va co duong di tu s den u}
    if (u = f) OR (u=0) then Break;
    Free[u] := False; {Co dinh nhan dinh u}
	{Dung dinh u toi uu nhan nhung dinh tu do ke voi u}
    for v := 1 to n do
      if Free[v] and (d[v] > d[u] + c[u, v]) then
        begin
          d[v] := d[u] + c[u, v];
          Trace[v] := u;
        end;
  until False;
end;

procedure PrintResult;
var
  fo: Text;
begin
  Assign(fo, OutputFile); Rewrite(fo);
  if d[f] = maxC then
    WriteLn(fo, 'There is no path from ', s, ' to ', f)
  else
    begin
      WriteLn(fo, 'Distance from ', s, ' to ', f, ': ', d[f]);
      while f <> s do
        begin
          Write(fo, f, '<-');
          f := Trace[f];
        end;
      WriteLn(fo, s);
    end;
  Close(fo);
end;

begin
  LoadGraph;
  Init;
  Dijkstra;
  PrintResult;
end.

