uses math;
const fi='seqgame.inp';
      fo='seqgame.out';
var a: array [1..1000000] of longint;
    n: longint;
    f: text;


procedure nhap;
var i: longint;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  for i:= 1 to n do read(f,a[i]);
end;


procedure sort(l,r: longint);
var i,j,x: longint;
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


function BinarySearch(num: longint): longint;
var l,r,k1,k2,m: longint;
begin
  l:=1; r:=n;
  k1:=0; k2:=0;
  repeat
    m:=(l+r) div 2;
    if a[m]>=num then r:=m else l:=m+1;
  until l=r;
  k1:=r;

  if a[r]>=num then k2:=k1-1
  else if k1<n then k2:=k1+1;

  if k2*k1=0 then exit(max(k1,k2));

  if abs(a[k1]-num)<abs(a[k2]-num) then exit(k1);
  exit(k2);
end;


procedure xuat(re: longint);
begin
  close(f);
  assign(f,fo);
  rewrite(f);
  write(f,re);
  close(f);
  halt;
end;


procedure xl;
var i,re,num,bs: longint;
begin
  sort(1,n);
  re:=high(longint);
  for i:= 1 to n do begin
    read(f,num);
    bs:= BinarySearch(-num);
    if bs>0 then begin
      re:= min(re,abs(a[bs]+num));
      if re=0 then xuat(0);
    end;
  end;
  xuat(re);
end;


begin
  nhap;
  xl;
end.
