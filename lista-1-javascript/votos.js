function calcularParticipacao() {
    let cidade = document.getElementById("cidade").value;
    let eleitores = parseInt(document.getElementById("eleitores").value);
    let votos = parseInt(document.getElementById("votos").value);

    if (!isNaN(eleitores) && !isNaN(votos) && eleitores >= 0 && votos >= 0) {
        let participacao = (votos / eleitores) * 100;

        document.getElementById("resultado").textContent = `Participação em ${cidade}: ${participacao.toFixed(2)}%`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira valores válidos (não negativos) para eleitores e votos.";
    }
}