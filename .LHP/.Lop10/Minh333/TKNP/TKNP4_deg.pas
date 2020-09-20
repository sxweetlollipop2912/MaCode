uses math;
const fi='TKNP4.inp';
      fo='TKNP4.out';
type maxn= 0..100000;
var r: array [maxn] of double;
    ma,mi,re: qword;
    min_re,minr: double;
    f: text;
    n: maxn;

procedure nhap;
var i: maxn;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  ma:=0;
  for i:= 0 to n-1 do begin
    read(f,r[i]);
    ma:=ma+trunc(r[i]);
  end;
  close(f);
end;



function cal(r0,r1,r2: double): double;
begin
  cal:=(r0*(r0+r1+r2)-r1*r2)/(r0+r2)/(r0+r1);
  exit(radtodeg(arccos(cal)));
end;


function check(r0: double): shortint;
var i: maxn;
    angle: double;
begin
  angle:=0;
  for i:= 0 to n-1 do
    angle:=angle+cal(r0,r[i],r[(i+1) mod n]);
  min_re:=angle-360;

  if min_re=0 then exit(0);
  if min_re<0 then exit(-1);
  exit(1);
end;


procedure findMinMax;  //check(max)=-1, max nho nhat
var l,m: qword;
begin
  l:=0;
  repeat
    m:=(l+ma) div 2;
    if check(m)<>-1 then l:=m+1 else ma:=m;
  until l>=ma;
  mi:=max(0,ma-1);
  //if ma-1 > 0 then mi:= ma-1 else mi:=0;
end;


procedure Find;
var m: qword;
    i: maxn;
begin
  for i:= 0 to n-1 do r[i]:=r[i]*10000;
  ma:=ma*10000;
  mi:=mi*10000;
  minr:=360;
  repeat
    m:=(ma+mi+1) div 2;
    if check(m)=-1 then ma:=m-1
    else begin
      mi:=m;
      if minr>min_re then begin minr:=min_re;
                                re:=m;
                          end;
    end;
  until mi>=ma;
end;


procedure xl;
var i: byte;
begin
  assign(f,fo);
  rewrite(f);
  findMinMax;
  Find;
  //writeln(f,minr:0:16);
  //for i:= 0 to n-1 do write(f,r[i]/10000:0:0,#32);
  writeln(f,(re/10000):0:4);
  close(f);
end;


begin
  nhap;
  xl;
end.
