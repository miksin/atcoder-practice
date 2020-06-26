const fs = require('fs')
const n = parseInt(fs.readFileSync('/dev/stdin', 'utf8').trim())

function primeFactorize(n) {
  const primes = []
  for (let p = 2; p * p <= n; p += 1) {
    if (n % p != 0) continue

    let e = 0
    while (n % p == 0) {
      n /= p
      e += 1
    }
    primes.push({ p, e })
  }

  if (n != 1) primes.push({ p: n, e: 1 })
  return primes
}

let count = 0
const primes = primeFactorize(n)
primes.forEach(prime => {
  let e = prime.e
  for (let i = 1; i <= e; i += 1) {
    e -= i;
    count += 1;
  }
})

console.log(count)
