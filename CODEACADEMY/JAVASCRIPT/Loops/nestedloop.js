let myPlaces = ['one', 'two', 'three'];
let friendPlaces = ['two', 'three', 'four'];

for(let myPlacesIndex = 0; myPlacesIndex<myPlaces.length; myPlacesIndex++) {
  //console.log(myPlaces[myPlacesIndex]);
  for(let friendPlacesIndex = 0; friendPlacesIndex<friendPlaces.length; friendPlacesIndex++) {
    //console.log(friendPlaces[friendPlacesIndex]);
    if(myPlaces[myPlacesIndex]===friendPlaces[friendPlacesIndex]) {
      console.log(myPlaces[myPlacesIndex]);
    }
  }
}
