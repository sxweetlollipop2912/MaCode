const fi='count2.inp';
      fo='count2.out';
var a: array [1..2000] of longint;
    n: integer;
    f: text;


procedure nhap;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  for n:= 1 to n do read(f,a[n]);
  close(f);
end;


procedure sort(l,r: integer);
var i,j: integer;
    x: longint;
begin
  i:=l; j:=r;
  x:=a[(i+j) div 2];
  while a[i]<x do inc(i);
  while a[j]>x do dec(j);
  if i<=j then begin
    x:=a[i];
    a[i]:=a[j];
    a[j]:=x;
    inc(i); dec(j);
  end;
  if i<r then sort(i,r);
  if l<j then sort(l,j);
end;


function check(x: longint): boolean;
var m,l,r: integer;
begin
  l:=1; r:=n;
  repeat
    m:=(l+r) div 2;
    if a[m]<x then l:=m+1 else r:=m;
  until l=r;
  if a[r]<>x then exit(false);
  if (r<n) and (a[r+1]=x) then exit(true);
  if (r>1) and (a[r-1]=x) then exit(true);
  exit(false);
end;


procedure xl;
var i,j: integer;
    re: longint;
begin
  assign(f,fo);
  rewrite(f);
  sort(1,n);
  re:=0;
  for i:= 1 to n-1 do
    for j:= i+1 to n do
      if check(a[i]+a[j]) then inc(re);
  write(f,re);
  close(f);
end;



begin
  nhap;
  xl;
end.
