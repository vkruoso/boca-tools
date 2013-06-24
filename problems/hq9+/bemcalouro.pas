program hq9;

var resposta : boolean;
var entrada : string;
var numero_de_casos_de_teste, contador, contador2 : integer;

begin
    readln(numero_de_casos_de_teste);
    
    for contador := 1 to numero_de_casos_de_teste do
    begin
        readln(entrada);
        resposta := false;
        for contador2 := 1 to length(entrada) do
        begin
            if entrada[contador2] = 'H' then
            begin
                resposta := true;
            end;
            if entrada[contador2] = '9' then
            begin
                resposta := true;
            end;
            if entrada[contador2] = 'Q' then
            begin
                resposta := true;
            end;
        end;

        if (resposta = true) then
        begin
            writeln('YES');
        end
        else
        begin
            writeln('NO');
        end;
    end;
end.
