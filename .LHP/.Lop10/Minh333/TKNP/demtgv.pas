uses math;
const fi='demtgv.inp';
      fo='demtgv.out';
type maxn= 0..1000;
     maxa= 0..1000000000;
var a,b : array [1..1000] of maxa;
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


function smin(x: maxa; l,r: maxn): maxn;
var m: maxn;
begin
  if (l=0) or (r=0) then exit(0);
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
  if (l=0) or (r=0) then exit(0);
  smax:=0;
  repeat
    m:=(l+r+1) div 2;
    if a[m]>x then r:=m-1 else l:=m;
  until l>=r;
  if a[r]=x then smax:=r
  else if a[l]=x then smax:=l;
end;


procedure xl;
var i,j,l,r: maxn;
    re,c:maxa;
    x: double;
begin

  //sort a
  for i:= 1 to n-1 do
    for j:= i+1 to n do
      if a[i]>a[j] then begin
        re:=a[i];
        a[i]:=a[j];
        a[j]:=re;
      end;

  re:=0;
  for i:= 1 to n do begin
    read(f,c);
    for j:= 1 to n do begin
      r:=1;

      x:=sqrt(abs(b[j]*b[j]-c*c));
      if (x>0) and (x=trunc(x)) then begin
        l:=smin(trunc(x),1,n);
        if l>0 then begin
          r:=smax(trunc(x),l,n);
          re:=re+r-l+1;
        end;
      end;

      x:=sqrt(b[j]*b[j]+c*c);
      if (x>0) and (x=trunc(x)) then begin
        l:=smin(trunc(x),r,n);
        if l>0 then begin
          r:=smax(trunc(x),l,n);
          re:=re+r-l+1;
        end;
      end;

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
