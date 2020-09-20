// maxn = 62
uses math;
const fi='bt10.inp';
      fo='bt10.out';
var n: longint;
    a: array [0..1] of qword;
    f: text;


procedure nhap;
begin
  assign(f,fi);
  reset(f);
  read(f,n);
  close(f);
end;


function fibo(n: longint): int64;
begin
  fibo:= trunc(((1/sqrt(5))*((1+sqrt(5))/2)**n) - ((1/sqrt(5))*((1-sqrt(5))/2)**n));
end;


procedure xl;
var p: byte;
    i: longint;
begin
  assign(f,fo);
  rewrite(f);
  p:=1;
  a[0]:=0; a[1]:=1;
  write(f,2**n - fibo(n) - fibo(n+1));
  close(f);
end;


begin
  nhap;
  xl;
end.
