//Phien ban Danh dau, dk: max(diem)<=10^8
const fi='ranking.inp';
      fo='ranking.out';
      pmax=100000000;//10^8
      mnmax=500000;
var c:array[0..pmax] of word;
    r:array[0..mnmax] of longint;
    m,n,k:1..mnmax;
    x:longint;
    f,g:text;

procedure update(x:longint);
begin
  while x>0 do
  begin
    inc(c[x]);
    x:=x-(x and -x);
  end;
end;

function rank(x:longint):word;
begin
  rank:=1;
  inc(x);
  while x<=pmax do
  begin
    inc(rank,c[x]);
    x:=x+(x and -x);
  end;
end;

begin
  assign(f,fi);reset(f);
  assign(g,fo);rewrite(g);
  readln(f,n,m);
  for n:=1 to n do
  begin
    read(f,x);
    r[n]:=rank(x);
    update(x);
  end;
  for m:=1 to m do
   begin
    readln(f,k);
    writeln(g,r[k]);
   end;
  close(f);close(g);
end.
