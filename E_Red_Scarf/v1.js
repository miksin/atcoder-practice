const fs = require('fs')
const inputs = fs.readFileSync('/dev/stdin', 'utf8').trim().split(/\s+/).map(s => parseInt(s))

const n = inputs.shift()
const arr = inputs.slice(0, n)
const allXor = arr.reduce((a, b) => a ^ b, 0)
const results = arr.map(a => allXor ^ a)

console.log(results.join(' '))
