const fi='MAXFLOW.INP';
      fo='MAXFLOW.OUT';
      max=1000;
type tc= array[1..max, 1..max] of integer;
var c,f: tc;
    trace: array[1..max] of integer;
    n,s,t,m,u,v,delta: integer;
function findpath: boolean;
var queue: array[1..max] of integer;
    front,rear: integer;
begin
      fillChar(trace,sizeof(trace),0);
      front:=1; rear:=1;
      queue[1]:=s;
      trace[s]:=n+1;
      repeat
             u:=queue[front]; inc(front);
             for v:=1 to n do
                   if (trace[v]=0) and (c[u,v]>f[u,v]) then begin
                         trace[v]:=u;
                         if v=t then begin
                               findpath:=true;
                               exit;
                         end;
                         inc(rear); queue[rear]:=v;
                   end;
      until front>rear;
      findpath:=false;
end;
procedure incflow;
begin
      delta:=maxint; v:=t;
      repeat
             u:=trace[v];
             if c[u,v]-f[u,v]<delta then delta:=c[u,v]-f[u,v];
             v:=u;
      until v=s;
      v:=t;
      repeat
             u:=trace[v];
             f[u,v]:=f[u,v]+delta;
             f[v,u]:=f[v,u]-delta;
             v:=u;
      until v=s;
end;
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      fillchar(c,sizeof(c),0);
      read(n,m,s,t);
      for m:=1 to m do read(u,v,c[u,v]);
      fillchar(f,sizeof(f),0);
      repeat
             if not findpath then break;
             incflow;
      until false;
      m:=0;
      for u:=1 to n do
            for v:=1 to n do
                  if f[u,v]>0 then begin
                        writeln('f[',u,',',v,']=',f[u,v]);
                        if u=s then inc(m,f[s,v]);
                  end;
      write('Max Flow: ',m);
      close(input); close(output);
end.
