{$MODE OBJFPC}
Const
	finp='hoitrai.inp';
    fout='hoitrai.out';
    maxN=300;
    inf=999999999;

Var
    fi,fo:text;
    d,dem:array[1..maxN,1..maxN] of integer;
    {
        d[i,j]: do dai duong di ngan nhat tu i den j
        dem[i,j]: so luong duong di ngan nhat tu i den j khac nhau
    }
    i,j,k,u,v,n,m,y:integer;

BEGIN
    Assign(fi,finp); Reset(fi);
    Assign(fo,fout); Rewrite(fo);

    Readln(fi,n,m,y);

    for i:=1 to n do
        for j:=1 to n do
        Begin
            dem[i,j]:=0;
            d[i,j]:=inf;
        End;

    for i:=1 to n do d[i,i]:=0;

    for i:=1 to m do
    Begin
        Readln(fi,u,v);
        d[u,v]:=1;
        dem[u,v]:=1;
        d[v,u]:=d[u,v];
        dem[v,u]:=dem[u,v];
    End;

    {Thuat toan floyd tim duong di ngan nhat giua moi cap dinh}
    for k:=1 to n do
     for i:=1 to n do
        for j:=1 to n do
        If d[i,j]>d[i,k]+d[k,j] then {Neu co duong di i->k->j ngan hon duong di i->j hien tai}
        Begin
            d[i,j]:=d[i,k]+d[k,j]; {Thay the duong di i->j hien tai bang duong di i->k->j}
            dem[i,j]:=dem[i,k]*dem[k,j]; {dem[i,j] la so luong duong di i->k->j khac nhau}
        End
        else
            if d[i,j]=d[i,k]+d[k,j] then {Neu co duong di i->k->j bang duong di i->j hien tai}
                dem[i,j]:=dem[i,j]+dem[i,k]*dem[k,j]; {Cong them so luong duong di i->k->j khac nhau vao dem[i,j]}

    for i:=1 to y do
    Begin
        Readln(fi,u,v);
        writeln(fo,dem[u,v]);
    End;

    Close(fi); Close(fo);
END.
