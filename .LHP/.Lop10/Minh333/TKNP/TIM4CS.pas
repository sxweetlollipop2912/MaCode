const fi='tim4cs.inp';
      fo='tim4cs.out';

var a: array [1..1000000] of int64;
    n: longint;
    x: int64;
    f: text;

procedure nhap;
begin
  assign(f,fi);
  reset(f);
  readln(f,n,x);
  for n:= 1 to n do read(f,a[n]);
  close(f);
end;


function TKNP_1: longint;
Var l, r, k: longint;
Begin
  l:=1; r:=n;
  Repeat
     k:=(l+r+1) div 2;
     If a[k]>=x Then r:=k-1 Else l:=k;
  Until l>=r;
  if a[l]<x then exit(l)
  else if a[r]<x Then exit(r) Else exit(0);
End;


function TKNP_2: longint;
Var l, r,k: longint;
Begin
  l:=1; r:=n;
  Repeat
    k:=(l+r+1) div 2;
    If a[k]>x Then r:=k-1 Else l:=k;
  Until l>=r;
  if a[l]<=x then exit(l)
  else if a[r]<=x Then exit(r) Else exit(0);
End;


function TKNP_3: longint;
Var l, r, k: longint;
Begin
  l:=1; r:=n;
  Repeat
    k:=(l+r) div 2;
    If a[k]<=x Then l:=k+1 Else r:=k;
  Until l>=r;
  If a[r]>x Then exit(r)
  else if a[l]>x then exit(l) Else exit(0);
End;



function TKNP_4: longint;
Var l, r, k: longint;
Begin
  l:=1; r:=n;
  Repeat
    k:=(l+r) div 2;
    If a[k]<x Then l:=k+1 Else r:=k;
  Until l>=r;
  if a[r]>=x then exit(r)
  else if a[l]>=x Then exit(l) Else exit(0);
End;


procedure xl;
begin
  assign(f,fo);
  rewrite(f);
  writeln(f,TKNP_1);
  writeln(f,TKNP_2);
  writeln(f,TKNP_3);
  write(f,TKNP_4);
  close(f);
end;


begin
  nhap;
  xl;
end.
