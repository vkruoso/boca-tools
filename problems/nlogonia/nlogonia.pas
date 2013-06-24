program nlogonia;
var n, ox, oy, x,y, i: integer;
begin
    read(n);
    while n <> 0 do
    begin
        read(ox, oy);
        for i := 1 to n do
        begin
            read(x,y);
            if (x=ox) or (y=oy) then
                writeln('divisa')
            else if (x>ox) and (y>oy) then
                writeln('NE')
            else if (x>ox) and (y<oy) then
                writeln('SE')
            else if (x<ox) and (y>oy) then
                writeln('NO')
            else
                writeln('SO');
        end;
        read(n);
    end;
end.
