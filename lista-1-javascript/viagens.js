function calcularViagens() {
    let numCaminhoes = parseInt(document.getElementById("caminhoes").value);
    let numAlqueires = parseInt(document.getElementById("alqueires").value);

    if (!isNaN(numCaminhoes) && !isNaN(numAlqueires) && numCaminhoes > 0 && numAlqueires > 0) {
        let viagensNecessarias = Math.ceil((numAlqueires * 250) / (numCaminhoes * 18));

        document.getElementById("resultado").textContent = `Serão necessárias ${viagensNecessarias} viagens de caminhão para transportar a colheita.`;
    } else {
        document.getElementById("resultado").textContent = "Erro: Insira valores válidos para caminhões e alqueires.";
    }
}