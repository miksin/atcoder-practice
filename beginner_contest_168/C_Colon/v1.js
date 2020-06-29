const inputs = require('fs')
  .readFileSync('/dev/stdin', 'utf8')
  .trim()
  .split(/\s+/)
  .map(s => parseInt(s))

const A = inputs[0]
const B = inputs[1]
const H = inputs[2]
const M = inputs[3]

const ratioH = (H * 60 + M) / (12 * 60)
const ratioM = M / 60
const theta = Math.abs(ratioH - ratioM) * (2 * Math.PI)

const C = Math.sqrt(A * A + B * B - 2 * A * B * Math.cos(theta))
console.log(C.toFixed(10))
