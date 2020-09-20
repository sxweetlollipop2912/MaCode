const fi='sinh_hv.inp';
      fo='sinh_hv.out';
var n,k: byte;
    f: text;
    a: array [1..100] of 0..1;

procedure nhap;
begin
  assign(f,fi);
  reset(f);
  read(f,k,n);
  close(f);
  fillchar(a,sizeof(a),0);
end;


procedure try(s: string; len: byte);
var i: byte;
    s1: string;
begin
  if len = k then begin
    writeln(f,s);
    exit;
  end;
  for i:= 1 to n do begin
    if a[i]=1 then continue;
    a[i]:=1;
    str(i,s1);
    try(s+s1+' ', len+1);
    a[i]:=0;
  end;
end;


procedure xl;
begin
  assign(f,fo);
  rewrite(f);
  try('',0);
  close(f);
end;


begin
  nhap;
  xl;
end.
