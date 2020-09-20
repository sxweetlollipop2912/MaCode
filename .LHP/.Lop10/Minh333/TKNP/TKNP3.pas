const fi='demtg.inp';
      fo='demtg.out';
type maxn= 0..1000;
     maxa= 0..1000000000;
var a,b: array [1..1000] of maxa;
    n: maxn;
    f: text;


procedure nhap;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  for n:= 1 to n do read(f,a[n]);
  for n:= 1 to n do read(f,b[n]);
end;


{procedure sort(l,r: maxn);
var i,j: maxn;
    x: maxa;
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
end;}


function search(b,c: maxa): maxa;
var l,r,left,right,m: maxn;
begin
  b:=b+c;
  c:=abs(b-c-c);
  l:=1; r:=n;

  repeat
    m:= (l+r) div 2;
    if a[m]<=c then l:=m+1 else r:=m;
  until l>=r;
  if a[r]>c then left:=r
  else exit(0);

  l:=r; r:=n;
  repeat
    m:= (l+r+1) div 2;
    if a[m]>=b then r:=m-1 else l:=m;
  until l>=r;
  right:=l;

  exit(right-left+1);
end;


procedure xl;
var i,j: maxn;
    re,c: maxa;
begin
  //sort(1,n);

  for i:= 1 to n-1 do
    for j:= i+1 to n do
      if a[i]>a[j] then begin
        re:=a[i]; a[i]:=a[j]; a[j]:=re;
      end;

  re:=0;
  for i:= 1 to n do begin
    read(f,c);
    for j:= 1 to n do re:=re+search(c,b[j]);
  end;
  close(f);
  assign(f,fo);
  rewrite(f);
  write(f,re);
  close(f);
end;


begin
  nhap;
  xl;
end.
