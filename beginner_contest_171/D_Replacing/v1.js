const fs = require('fs')
const inputs = fs
  .readFileSync('/dev/stdin', 'utf8')
  .trim()
  .split(/\s+/)
  .map(s => parseInt(s))

const len = inputs.shift()
let sum = 0
const numCount = {}
for (let i = 0; i < len; i++) {
  const num = inputs.shift()
  numCount[`${num}`] = (numCount[`${num}`] || 0) + 1
  sum += num
}

const q = inputs.shift()

for (let i = 0; i < q; i += 1) {
  const b = inputs.shift()
  const c = inputs.shift()
  
  const amount = numCount[`${b}`] || 0
  sum += amount * (c - b)
  console.log(sum)
  
  numCount[`${c}`] = (numCount[`${c}`] || 0) + amount
  numCount[`${b}`] = 0
}

