let cards = ['Diamond', 'Spade', 'Heart', 'Club'];
let currentCard = 'Heart';

while(currentCard!='Spade') {
  console.log(currentCard);
  currentCard = cards[Math.floor(Math.random() * 4)];
}

console.log('Found a spade!')
