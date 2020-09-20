const fi='demtgv.inp';
      fo='demtgc_trau.out';
type maxn= 0..100000;
     maxa= 0..1000000000;
var a,b: array[maxn] of maxa;
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


function check(i,j,k: maxa): boolean;
begin
  //if (i<>j) and (i<>k) and (j<>k) then exit(false);
  if (abs(i-j)>=k) or (i+j<=k) then exit(false);
  if (sqr(i)<>sqr(j)+sqr(k)) and (sqr(j)<>sqr(i)+sqr(k)) and (sqr(k)<>sqr(i)+sqr(j)) then exit(false);
  //writeln(f1,i,#32,j,#32,k);
  //writeln(f1,i,#32,k,#32,j);
  exit(true);
end;


procedure xl;
var i,j,k: maxn;
    re,c: maxa;
begin
  assign(f1,fo);
  rewrite(f1);
  re:=0;
  for i:= 1 to n do begin
    read(f,c);
    for j:= 1 to n do
      for k:= 1 to n do
        if check(c,b[k],a[j]) then inc(re);
  end;

  close(f);
  //assign(f,fo);
  //rewrite(f);
  write(f1,re);
  close(f1);
end;


begin
  nhap;
  xl;
end.
