uses math;
const fi='demtgc.inp';
      fo='demtgc.out';
type maxn= 0..100000;
     maxa= 0..1000000000;  //10^9
var a,b: array [1..100000] of maxa;
    n: maxn;
    f,f1: text;

procedure nhap;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  for n:= 1 to n do read(f,a[n]);
  for n:= 1 to n do read(f,b[n]);
end;


function smin(x: maxa; l,r: maxn): maxn;
var m: maxn;
begin
  if (l>r) or (l=0) or (r=0) then exit(0);
  smin:=0;
  repeat
    m:=(l+r) div 2;
    if a[m]<x then l:=m+1 else r:=m;
  until l>=r;
  if a[r]=x then smin:=r
  else if a[l]=x then smin:=l;
end;


function smax(x: maxa; l,r: maxn): maxn;
var m: maxn;
begin
  if (l>r) or (l=0) or (r=0) then exit(0);
  smax:=0;
  repeat
    m:=(l+r+1) div 2;
    if a[m]>x then r:=m-1 else l:=m;
  until l>=r;
  if a[r]=x then smax:=r
  else if a[l]=x then smax:=l;
end;


function smax_approx(x: maxa): maxn;
var m,l,r: maxn;
begin
  l:=1;
  r:=n;
  repeat
    m:=(l+r+1) div 2;
    if a[m]>x then r:=m-1 else l:=m;
  until l>=r;
  if a[l]<=x then smax_approx:=l
  else smax_approx:=0;
end;


procedure sorta(l,r: maxn);
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
  if i<r then sorta(i,r);
  if l<j then sorta(l,j);
end;


procedure sortb(l,r: maxn);
var i,j: maxn;
    x: maxa;
begin
  i:=l; j:=r;
  x:=b[(i+j) div 2];
  while b[i]<x do inc(i);
  while b[j]>x do dec(j);
  if i<=j then begin
    x:=b[i];
    b[i]:=b[j];
    b[j]:=x;
    inc(i); dec(j);
  end;
  if i<r then sortb(i,r);
  if l<j then sortb(l,j);
end;


procedure xl;
var i,j,l,r: maxn;
    re,c,x,re_old: maxa;
begin
  re:=0;
  sorta(1,n);
  sortb(1,n);

  for i:= 1 to n do begin
    read(f,c);
    for j:= 1 to n do begin

      if (j>1) and (b[j-1]=b[j]) then begin
        re:=re+re_old;
        continue;
      end;

      r:=1;
      if c=b[j] then begin
        re_old:=smax_approx(c+b[j]-1);
        re:=re+re_old;
        continue;
      end;

      re_old:=0;
      if max(c,b[j]) < 2*min(c,b[j]) then begin    // canh lon lam day
        x:= min(c,b[j]);
        l:=smin(x,1,n);
        if l>0 then begin
          r:=smax(x,l,n);
          re_old:=r-l+1;
        end;
      end;

      x:= max(c,b[j]);                             // canh nho lam day
      l:= smin(x,r,n);
      if l>0 then begin
        r:=smax(x,l,n);
        re_old:=re_old+r-l+1;
      end;
      re:=re+re_old;
    end;
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
