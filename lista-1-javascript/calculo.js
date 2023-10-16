let a = parseFloat(prompt("Digite o valor de 'a':"));
let b = parseFloat(prompt("Digite o valor de 'b':"));
let c = parseFloat(prompt("Digite o valor de 'c':"));

if (c !== 0) {

    let resultado = (a + b) / c;

    console.log(`O resultado de (${a} + ${b}) / ${c} é igual a ${resultado}`);
} else {
    console.log("Erro: A divisão por zero não é permitida.");
}