function calcularReajuste() {
    let nome = document.getElementById("nome").value;
    let salario = parseFloat(document.getElementById("salario").value);
    let percentual = parseFloat(document.getElementById("percentual").value);

    if (!isNaN(salario) && !isNaN(percentual)) {
        let novoSalario = salario + (salario * percentual / 100);
        document.getElementById("resultado").textContent = `Novo salário de ${nome}: R$ ${novoSalario.toFixed(2)}`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira valores numéricos válidos.";
    }
}