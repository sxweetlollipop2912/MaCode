const fi='dayngoac.inp';
      fo='dayngoac.out';
var s: string;
    n,top: byte;
    a: array [1..100] of char;
    f1,f2: text;


function check(s: string) : boolean;
var i: byte;
begin
  top:=0;
  for i:= 1 to length(s) do begin
    if (s[i]='(') or (s[i]='[') or (s[i]='{') then begin inc(top);
                                                         a[top]:=s[i];
                                                   end
    else begin
      if top<1 then exit(false);
      case s[i] of
        ')' : if a[top]<>'(' then exit(false);
        ']' : if a[top]<>'[' then exit(false);
        '}' : if a[top]<>'{' then exit(false);
        else exit(false);
      end;
      dec(top);
    end
  end;
  exit(true);
end;


procedure xl;
begin
  assign(f1,fi);
  reset(f1);
  assign(f2,fo);
  rewrite(f2);
  readln(f1,n);
  while n>0 do begin
    readln(f1,s);
    if (check(s)) and (top<1) then writeln(f2,'TRUE')
    else writeln(f2,'FALSE');
    dec(n);
  end;
  close(f1);
  close(f2);
end;


begin
 xl;
end.