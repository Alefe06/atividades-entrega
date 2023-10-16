class Triangulo {
    constructor(lado1, lado2, lado3) {
        this.lado1 = lado1;
        this.lado2 = lado2;
        this.lado3 = lado3;
    }

    tipo() {
        if (this.lado1 === this.lado2 && this.lado2 === this.lado3) {
            return "Equilátero";
        } else if (this.lado1 === this.lado2 || this.lado1 === this.lado3 || this.lado2 === this.lado3) {
            return "Isósceles";
        } else {
            return "Escaleno";
        }
    }
}

const listaTriangulos = [
    new Triangulo(3, 3, 3),
    new Triangulo(3, 4, 4),
    new Triangulo(3, 4, 5),
    new Triangulo(34, 64, 34),
    new Triangulo(63, 8, 53),
];

const triangulosElement = document.getElementById("triangulos");

listaTriangulos.forEach((triangulo, index) => {
    const div = document.createElement("div");
    div.textContent = `Triângulo ${index + 1}: Lados (${triangulo.lado1}, ${triangulo.lado2}, ${triangulo.lado3}), Tipo: ${triangulo.tipo()}`;
    triangulosElement.appendChild(div);
});