const fs = require('fs')
const inputs = fs.readFileSync('/dev/stdin', 'utf8').trim().split(/\s+/).map(s => parseInt(s))

const n = inputs[0]
const arr = inputs.slice(1, n + 1).sort((a, b) => a - b)
const aMax = arr[arr.length - 1]

let count = 0
const dp = new Array(aMax + 1).fill(true)
arr.forEach((a, index) => {
  if (dp[a]) {
    for (let i = 1; i * a <= aMax; i++) {
      dp[i * a] = false
    }
    if (a !== arr[index + 1]) {
      count += 1
    }
  }
})
console.log(count)
