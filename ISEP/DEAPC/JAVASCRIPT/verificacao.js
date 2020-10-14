function verificacao() {
    var form = document.getElementById("inscricao");
    var primNome = form.elements[0].value;
    var sobrNome = form.elements[1].value;
    //Esta parte do codigo vai buscar os dados de um meno radio
    //Escolhe o radio de "sexo"
    var tick = document.getElementsByName("sexo");
    //Procura por todos os elementos de "sexo" para encontrar qual o que foi escolhido
    for (let i = 0; i < tick.length; i++) {
        if (tick[i].checked) {
            var sexo = tick[i].value;
            break;
        }
        else {
            var sexo = "";
        }
    }
    //Faz o mesmo mas para o radio do titulo
    tick = document.getElementsByName("titulo");
    for (let i = 0; i < tick.length; i++) {
        //Debug: console.log("Isto correu ");
        if (tick[i].checked) {
            var titulo = tick[i].value;
            break;
        }
        else {
            var titulo = "";
        }
    }
    var instit = form.elements[8].value;
    var email = form.elements[9].value;
    var erro = false;
    var errPrimNome = "", errSobrNome = "", errSexo = "", errTitulo = "", errInstit = "", errEmail = "";
    //Debug: alert(primNome + sobrNome + sexo + titulo + instit + email);
    //Nota, para a proxima vez uso um array para nao estar a copiar e colar
    
    if(primNome=="") {
        erro = true;
        errPrimNome = "- o nome;\n";
    }
    if(sobrNome=="") {
        erro = true;
        errSobrNome = "- o sobrenome;\n";
    }
    if(sexo=="") {
        erro = true;
        errSexo = "- o sexo;\n";
    }
    if(titulo=="") {
        erro = true;
        errTitulo = "- o titulo;\n"
    }
    if(instit=="") {
        erro = true;
        errInstit = "- o instituto;\n";
    }
    if(email=="") {
        erro = true;
        errEmail = "- o email;\n";
    }
    else {
        //Verifica se o e-mail introduzido é invalido
        //Obviamente que isto pode ser expandido
        if(email.match(/[@]/gi).length>1) {
            erro = true;
            errEmail = "- o email introduzido é válido;\n"
        }
    }
    
    if(erro) {
        alert("Insira:\n" + errPrimNome + errSobrNome + errSexo + errTitulo + errInstit + errEmail);
        return false;
    }
    //Nota: nao é necessário retornar o verdadeiro para a verificação da form
}
