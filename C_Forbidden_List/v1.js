const fs = require('fs')
const inputs = fs.readFileSync('/dev/stdin', 'utf8').trim().split(/\s+/).map(s => parseInt(s))

const x = inputs[0]
const n = inputs[1]
const pSet = new Set()

inputs.slice(2, n + 2).forEach(p => pSet.add(p))

let diff = 0
while (true) {
  if (!pSet.has(x - diff)) {
    console.log(x - diff)
    break;
  }
  if (!pSet.has(x + diff)) {
    console.log(x + diff)
    break;
  }
  diff += 1
}
