//By Ngo Duc Minh
Type size=-1..300;
     node=record colo,c1,c2,h:integer;end;

var t:array[size] of node;
    n,d:integer;
    f:text;
    dir1,dir2:string;
    point:real;

procedure data;
var i,k:integer;
begin
 fillchar(t,sizeof(t),0);
 assign(f,dir1+'\prunef.inp');reset(f);
 readln(f,n,d);
 for i:=0 to n-1 do
 with t[i] do
  begin
   c1:=-1;c2:=-1;
   readln(f,k,colo,k);
   if colo=0 then h:=-1 else h:=1;
   if k>0 then readln(f,c1);
   if k=2 then readln(f,c2);
  end;
 close(f);
end;

procedure dfs(i:integer);
begin
 with t[i] do
  begin
   if c1>0 then
    begin
      dfs(c1);
      h:=h+t[c1].h;
    end;
   if c2>0 then
    begin
      dfs(c2);
      h:=h+t[c2].h;
    end;
  end;
end;

procedure solution;
var sts,sgk,dd,i:integer;
begin
 readln(dir1);
 readln(dir2);
 data;
 dfs(0);
 d:=t[0].h-d;
 assign(f,dir1+'\prunef.out');reset(f);
 readln(f,sgk);
 close(f);
 assign(f,dir2+'\prunef.out');reset(f);
 readln(f,sts);
 if sts=sgk then
  if sts=-1 then point:=1 else point:=0.5
 else point:=0;
 if sts>-1 then
  begin
   dd:=0;
   for sts:=1 to sts do
    begin
     read(f,i);dd:=dd+t[i].h;
    end;
   if dd=d then point:=point+0.5;
  end;
 close(f);
 write(point:0:2);
end;

Begin
 solution;
end.
