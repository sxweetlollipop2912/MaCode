Const
	finp='bang.inp';
    fout='bang.out';
    maxN=500;
    inf=999999999;
    td:array[1..4] of shortint=(1,0,-1,0);
    tc:array[1..4] of shortint=(0,1,0,-1);

Var
	fi,fo:text;
	d:array[1..maxN,1..maxN] of integer;
    free:array[1..maxN,1..maxN] of boolean;
    table:array[1..maxN,1..maxN] of integer;
    N,M,L,i,j,min:integer;
    Xi,Xj,Yi,Yj:integer;

Procedure DocFile;
Var i,j:integer;
Begin
	Readln(fi,N,M,Xi,Xj,Yi,Yj);
    For i:=1 to N do
    Begin
    	For j:=1 to M do Read(fi,table[i,j]);
        Readln(fi);
    End;
End;

Procedure Dijkstra;
Var ii,i,j,ui,uj,vi,vj,min,k,w:integer;
Begin
	For i:=1 to N do
    	For j:=1 to M do
        Begin
            d[i,j]:=inf;
            free[i,j]:=true;
        End;
    d[Xi,Xj]:=0;

    Repeat
	ui:=0; uj:=0; min:=inf;
	For i:=1 to N do
    	For j:=1 to M do
        	if free[i,j] and (d[i,j]<min) then
            Begin
            	min:=d[i,j];
                ui:=i; uj:=j;
            End;
    if (ui=Yi) and (uj=Yj) then break;
    free[ui,uj]:=false;
    For k:=1 to 4 do
    Begin
		vi:=ui+td[k];
        vj:=uj+tc[k];
        if (vi>=1) and (vi<=N) and (vj>=1) and (vj<=M) then
			if free[vi,vj] then
				if d[vi,vj]>d[ui,uj]+table[vi,vj] then
					d[vi,vj]:=d[ui,uj]+table[vi,vj];
    End;
	Until false;

End;

BEGIN
    Assign(fi,finp); Reset(fi);
    Assign(fo,fout); Rewrite(fo);

	DocFile;
	Dijkstra;
    writeln(fo,d[Yi,Yj]);

    Close(fi); Close(fo);
END.
