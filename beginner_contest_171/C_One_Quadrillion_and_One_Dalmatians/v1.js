const fs = require('fs')
const chars = 'abcdefghijklmnopqrstuvwxyz'
 
function changeBase(value) {
  let result = ''
  while (value > 0) {
    const remand = value % 26
    const c = chars[(remand + 25) % 26]
    result = c + result
    if (remand === 0) {
      value = Math.floor(value / 26) - 1
    } else {
      value = Math.floor(value / 26)
    }
  }
	return result
}
 
const inputValue = parseInt(fs.readFileSync('/dev/stdin', 'utf8'))
console.log(changeBase(inputValue))
