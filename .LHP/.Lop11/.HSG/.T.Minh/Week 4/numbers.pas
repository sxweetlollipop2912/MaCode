//By Ngo Duc Minh
const fi='numbers.inp';
      fo='numbers.out';
var p:array[0..18] of int64;//p[i]=8^i
    d:array[-1..18] of byte;//digits=s=limit
    a,b,res:int64;
    s:string;
    k,len:byte;//length(s)=length(d)

function calc(i:byte):int64;
Begin
 if i>len then exit(1);calc:=0;
 if d[i-1]<>d[i-2] then
  begin
   //Bottom Lines
   if d[i]>0 then for k:=0 to d[i]-1 do
    if (k<>d[i-1])and(k<>d[i-2]) then
     if i=1 then calc:=calc+9*p[len-2] else calc:=calc+p[len-i];
   //Top Line
   if (d[i]<>d[i-1])and(d[i]<>d[i-2]) then calc:=calc+calc(i+1);
  end;
end;

function get(a:int64):int64;
begin
  if a<0 then exit(0);
  str(a,s);len:=length(s);
  for len:=1 to len do d[len]:=ord(s[len])-48;
  d[0]:=10;d[-1]:=0;
  if len=1 then exit(d[1]+1);
  p[0]:=1;for k:=1 to len do p[k]:=p[k-1]*8;
  res:=calc(1);
  p[0]:=1;p[1]:=9;p[2]:=81;for k:=3 to len do p[k]:=p[k-1]*8;
  for k:=0 to len-1 do res:=res+p[k];
  exit(res);
end;

begin
 assign(input,fi);reset(input);
 readln(a,b);close(input);
 assign(output,fo);rewrite(output);
 writeln(get(b)-get(a-1));
 close(output);
end.
