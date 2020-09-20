const fi='BT1.inp';
      fo='BT1.out';
var n: integer;
    a: array [0..2] of qword;
    f: text;


procedure nhap;
begin
  assign(f,fi);
  reset(f);
  read(f,n);
  close(f);
end;


procedure xl;
var i,cur: integer;
begin
  assign(f,fo);
  rewrite(f);
  cur:=-1;
  a[0]:=1; a[1]:=1; a[2]:=2;
  for i:= 1 to n-2 do begin
    inc(cur);
    a[cur mod 3] := a[cur mod 3] + a[(cur+1) mod 3] + a[(cur+2) mod 3];
  end;
  write(f,a[cur mod 3]);
  close(f);
end;


begin
  nhap;
  xl;
end.