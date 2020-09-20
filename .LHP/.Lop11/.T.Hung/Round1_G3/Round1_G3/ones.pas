const fi='ones.inp';
      fo='ones.out';
var f:text;
    n, t, i:integer;
    s:ansistring;
    hold:longint;

procedure bigdiv1(a : ansistring; b : longint);
var
        s : longint;
	i : Integer;
	c : string;
begin
	hold := 0;
	c := '';
	for i := 1 to Length(a) do
	begin
	        hold := hold * 10 + ord(a[i]) -48;
		s := hold div b;
		hold := hold mod b;
		c := c + chr(s + 48);
	end;
	while (Length(c) > 0) and (c[1] = '0') do delete(c, 1, 1);
end;

begin
        assign(f,fi);
        reset(f);
        readln(F,n);
        close(F);

        if n = 1 then
        begin
                assign(f,fo);
                rewrite(f);
                write(f,1);
                close(f);
        end
         else
         begin

                s:='11';
                repeat
                bigdiv1(s,n);
                t:=length(s);
                if hold = 0 then
                begin
                        assign(f,fo);
                        rewrite(F);
                        write(F,length(s));
                        close(f);
                        exit;
                end
                 else s:=s+'1';
                until false;
         end;
end.

