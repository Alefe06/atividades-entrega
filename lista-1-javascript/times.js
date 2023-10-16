function calcularPontos() {
    let nomeTime = document.getElementById("nomeTime").value;
    let vitorias = parseInt(document.getElementById("vitorias").value);
    let empates = parseInt(document.getElementById("empates").value);

    if (!isNaN(vitorias) && !isNaN(empates)) {
        let pontos = (vitorias * 3) + empates;
        document.getElementById("resultado").textContent = `O time ${nomeTime} possui ${pontos} pontos.`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira valores numéricos válidos.";
    }
}