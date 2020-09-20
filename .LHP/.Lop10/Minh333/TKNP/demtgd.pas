const fi='demtgd.inp';
      fo='demtgd.out';
type maxn= 0..100000;
     maxa= 0..1000000000;
     aa= ^integer;
var a,b,c: array [1..100000] of maxa;
    n: maxn;
    f: text;


procedure nhap;
begin
  assign(f,fi);
  reset(f);
  readln(f,n);
  for n:= 1 to n do read(f,a[n]);
  for n:= 1 to n do read(f,b[n]);
  for n:= 1 to n do read(f,c[n]);
  close(f);
end;


procedure xl;
var i,j,k,d: maxn;
    old: maxa;
    re: 0..1000000000000000; //10^15 = maxn^3
begin
  assign(f,fo);
  rewrite(f);
  //sort a b c
  i:=1; j:=1; k:=1;
  re:=0;
  old:=0;
  while (i<=n) and (j<=n) and (k<=n) do begin
    if (a[i]<>old) or (b[j]<>old) or (c[k]<>old) then begin
      re:=re+d*d*d;
      d:=0;
    end;
    if (a[i]=b[j]) and (a[i]=c[k]) then begin
      old:= a[i];
      inc(d);
      inc(i); inc(j); inc(k);
      continue;
    end;
    if (a[i]<b[j]) or (a[i]<c[k]) then inc(i);
    if (b[j]<a[i]) or (b[j]<c[k]) then inc(j);
    if (c[k]<a[i]) or (c[k]<b[j]) then inc(k);
  end;
  write(f,re+d*d*d);
  close(f);
end;


begin
  nhap;
  xl;
end.