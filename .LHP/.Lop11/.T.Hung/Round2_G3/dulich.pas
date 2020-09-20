const fi='dulich.inp';
      fo='dulich.out';
      maxN = 201;
      maxW = 15000;
var w: array[1..maxN, 1..maxN] of real;
    x, y: array[1..maxN] of integer;
    k2:array[1..maxN] of real;
    k: array[1..maxN,1..maxN] of boolean;
    n, dem: Integer;
    kq, min:real;
    f:text;

procedure Enter;
var i, u, v, j: Integer;
begin
        assign(f,fi); reset(f);
        ReadLn(f,n);
        for u := 1 to n do
                for v := 1 to n do w[u, v] := maxW + 1;
        for i := 1 to n do ReadLn(f,x[i],y[i]);
        for i := 1 to n-1 do
        for j:=i+1 to n do
        begin
                w[i,j]:=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
                w[j,i]:=w[i,j];
        end;
        close(f);
end;


procedure dfs(s:byte);
var i:integer; kq:real;
begin
        for i:=1 to n do
        if k[s,i] = false then
                if w[s,i] <> maxW+1 then
                begin
                        if kq < w[s,i] then kq:=w[s,i];
                        k[s,i]:=true;
                        k[i,s]:=true;
                        if i = 2 then
                        begin
                                inc(dem);
                                k2[dem]:=kq;
                                kq:=0;
                                dfs(1);
                        end;
                        dfs(i);
                        k[s,i]:=false;
                        k[i,s]:=false;
                end;
end;

procedure PrintResult;
var v: Integer;
begin
        assign(f,fo); rewrite(f);
        fillchar(k,sizeof(k),false);
        dfs(1);
        min:=999999999;
        for dem:=1 to dem do if min > k2[dem] then min:=k2[dem];
        write(f,min:0:3);
        close(f);
end;

begin
        Enter;
        printresult;
end.
