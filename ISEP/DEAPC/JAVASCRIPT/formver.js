function verificacaoformulario() {
    var form = document.getElementById('formulario');
    var erro = false;
    var contador = 0;
    for (let i = 0; i < 10; i += 2) {
        var nome = form.elements[i].value;
        var idade = form.elements[i + 1].value;
        erro = false;
        var mensagemErro = "Erro: \n";

        if (!/^[a-zA-Z]+$/.test(nome)) {
            erro = true;
            mensagemErro = mensagemErro.concat("-Nome inválido\n");
        }
        if (!idade.match(/^\d{4}-\d{2}-\d{2}$/)) {
            erro = true;
            mensagemErro = mensagemErro.concat("-Data inválida\n");
        }
        if (nome == "" && idade == "" && i != 0) {
            erro = false;
            mensagemErro = "Erro: \n";
        }
        contador++;
        //Debug: console.log(nome + ' ' + idade);

        if (erro) {
            alert(mensagemErro);
            return false;
            break;
        }
    }
    erro = true;
    for (let i = 20; i < 22; i++) {
        if (form.elements[i].checked) {
            erro = false;
        }
    }
    if (erro) {
        mensagemErro = mensagemErro.concat("-Escolher método de ordenação")
        alert(mensagemErro);
        return false;
    }
}
