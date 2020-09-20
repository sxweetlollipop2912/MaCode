Type co2d=record x,y:integer end;
Var f1,f2:text;
    A:array[1..1000] of co2d;
    gk,ts:array[1..2000] of integer;
    n,ngk,nts:integer;
    dir1,dir2:string;
    lgk,lts:integer;

function iden(i,j:integer):boolean;
begin
 exit((a[i].x=a[j].x)and (a[i].y=a[j].y));
end;

function identical:boolean;
var i,j:integer;
    ok:boolean;
begin
 if nts<>ngk then Exit(False);
 //Tim 1 dinh i cua TS trung voi dinh 1 cua GK
 for i:=1 to nts+1 do if iden(ts[i],gk[1]) then break;
 if i>nts then Exit(False);
 if ngk=1 then Exit(True);

 for j:=1 to nts do ts[nts+j]:=ts[j];

 //kiem tra chieu thuan
 ok:=true;
 for j:=2 to ngk do if not iden(gk[j],ts[i+j-1]) then
  begin ok:=false;break;
  end;
 if ok then Exit(true);

 //kiem tra chieu nguoc
 for i:=2*nts downto nts do if iden(ts[i],gk[1]) then break;
 if i=nts then Exit(False);
 for j:=2 to nts do if not iden(gk[j],ts[i-j+1]) then Exit(False);
 Exit(True);
end;

BEGIN
    readln(dir1);
    readln(dir2);

    assign(f1,dir1+'\baoloi-n.inp');reset(f1);
    readln(f1,n);
    for n:=1 to n do with a[n] do readln(f1,x,y);
    close(f1);

    assign(f1,dir1+'\baoloi-n.out');reset(f1);
    assign(f2,dir2+'\baoloi-n.out');reset(f2);

    lgk:=0;
    lts:=0;
    while not seekeof(f1) do
     begin
      inc(lgk);
      readln(f1,ngk);
      for ngk:=1 to ngk do read(f1,gk[ngk]);readln(f1);
      if not seekeof(f2) then
       begin
        readln(f2,nts);
        for nts:=1 to nts do read(f2,ts[nts]);readln(f2);
        if Identical then inc(lts);
       end;
     end;
    close(f1);close(f2);

    {------------------------------------------------------------}
    write(lts/lgk:0:2);

END.
