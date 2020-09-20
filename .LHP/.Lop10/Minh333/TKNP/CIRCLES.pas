// RAD ver
uses math;
const fi='circles.inp';
      fo='circles.out';
      pi= 6.2831853071795862;
type maxn = 0..1000;
     maxa = 1..1000;
     maxr = double;
var a: array [maxn] of maxa;
    min_re, minr: maxr;
    ma, mi, re, r: maxr;
    n: maxn;
    f: text;


procedure Prepare;
var i: maxn;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  r:=0;
  for i:= 0 to n-1 do begin
    read(f,a[i]);
    ma:=ma + a[i];
  end;
  close(f);
end;



function cal(r0: maxr; r1, r2: maxa): double;
var a,b,c: double;
begin
  cal:=(r0*(r0+r1+r2)-r1*r2)/(r0+r2)/(r0+r1);
  exit(arccos(cal));
end;


function result(angle: double): shortint;
begin
  min_re:=angle-pi;
  if min_re=0 then exit(0);
  if min_re<0 then exit(-1);
  exit(1);
end;


function check(r0: maxr): shortint;
var i: maxn;
    angle: double;
begin
  angle:=0;
  for i:= 0 to n-1 do
    angle:=angle+cal(r0,a[i],a[(i+1) mod n]);
  exit(result(angle));
end;


procedure SetMinMax;
var l,m: 0..1000000;  // maxa * maxn
begin
  l:=0;
  repeat
    m:=trunc((l+ma) / 2);
    if check(m)=1 then l:=m+1
    else ma:=m;
  until l>=ma;
  mi:= max(0,ma-1);
end;


procedure Find;
var m: maxr;
begin
  minr:=1;
  m:= (ma + mi) / 2;
  while (mi<>m) and (ma<>m) do begin
    if check(m)=1 then mi:=m
    else ma:=m;
    if abs(min_re) < minr then begin
      minr:=abs(min_re);
      re:=m;
    end;
    m:= (ma+mi) / 2;
  end;
end;


procedure Execute;
begin
  assign(f,fo);
  rewrite(f);
  SetMinMax;
  Find;
  writeln(f,re:0:8);
  close(f);
end;


begin
  Prepare;
  Execute;
end.