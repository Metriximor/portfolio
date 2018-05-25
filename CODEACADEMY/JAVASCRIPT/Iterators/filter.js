let randomNumbers = [375, 200, 3.14, 7, 13, 852];
let smallNumbers = randomNumbers.filter(function(randomNumbers) {
  return randomNumbers<250;
});
// Call .filter() on randomNumbers below


let favoriteWords = ['nostalgia', 'hyperbole', 'fervent', 'esoteric', 'serene'];

let longFavoriteWords = favoriteWords.filter(word => {
  return word.length > 7;
});

// Refactor the code above using arrow function syntax
