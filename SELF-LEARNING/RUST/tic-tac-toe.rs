extern crate rand;

use core::fmt;
use std::io::stdin;
use Piece::*;
use rand::Rng;

#[derive(Copy, Clone, PartialEq)]
enum Piece {
    Empty,
    Player1,
    Player2,
}

impl fmt::Display for Piece {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Empty => write!(f, " "),
            Player1 => write!(f, "X"),
            Player2 => write!(f, "O")
        }
    }
}

impl fmt::Debug for Piece {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Empty => write!(f, "No one"),
            Player1 => write!(f, "Player"),
            Player2 => write!(f, "Computer")
        }
    }
}

fn print_board(board: &[[Piece; 3]; 3]) {
    let mut i = 0;
    println!("   1   2   3  ");
    println!(" ┼───┼───┼───┤");
    println!("A│ {} │ {} │ {} │", board[i][0], board[i][1], board[i][2]);
    i += 1;
    println!(" ┼───┼───┼───┤");
    println!("B│ {} │ {} │ {} │", board[i][0], board[i][1], board[i][2]);
    i += 1;
    println!(" ┼───┼───┼───┤");
    println!("C│ {} │ {} │ {} │", board[i][0], board[i][1], board[i][2]);
    println!(" ┴───┴───┴───┘")
}

fn fill_board(xy: (usize, usize), player: Piece, board: &mut [[Piece; 3]; 3]) {
    board[xy.0][xy.1] = player;
}

fn board_has_free_space(board: &[[Piece; 3]; 3]) -> bool {
    for i in board.iter() {
        for j in i.iter() {
            if *j == Empty {
                return true;
            }
        }
    }
    false
}

fn read_player_move() -> Result<(usize, usize), String> {
    println!("Choose Coordinates: (e.g. A1 or C2)");
    let mut input_text = String::new();
    stdin().read_line(&mut input_text).expect("Invalid value introduced!");
    input_text.pop();
    if input_text.len() != 2 {
        return Err("Invalid move!".to_string());
    }
    let mut input_chars = input_text.chars();
    let x_char = input_chars.next().expect("First Coord is invalid");
    let mut x: usize = 0;
    match x_char {
        'A' => x = 0,
        'B' => x = 1,
        'C' => x = 2,
        _ => return Err("Invalid first coord".to_string())
    }
    let y = (input_chars.next().expect("Second coord is invalid").to_digit(10).expect("Invalid digit") - 1) as usize;
    if y > 2 || y < 0 {
        return Err("Invalid Y coord".to_string());
    }
    Ok((x, y))
}

fn move_is_illegal(xy: (usize, usize), board: &[[Piece; 3]; 3]) -> bool {
    if board[xy.0][xy.1] != Empty {
        return true;
    }
    false
}

fn check_for_win(board: &[[Piece; 3]; 3]) -> (bool, Piece) {
    for i in 0..board.iter().len() {
        //Check for horizontal victory
        if board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != Empty {
            return (true, board[i][0]);
        }
        //Check for vertical victory
        if board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != Empty {
            return (true, board[0][i]);
        }
    }
    //Check for diagonal victory
    if ((board[1][1] == board[0][0] && board[1][1] == board[2][2]) ||
        (board[1][1] == board[0][2] && board[1][1] == board[2][0])) && (board[1][1] != Empty) {
        return (true, board[1][1]);
    }
    (false, Empty)
}

fn main() {
    use Piece::*;
    let mut board = [[Empty; 3]; 3];
    while board_has_free_space(&board) {
        print_board(&board);
        //Player Turn
        let player_move = read_player_move();
        match player_move {
            Err(e) => {
                println!("{}", e);
                continue;
            }
            Ok(m) => {
                if move_is_illegal(m, &board) {
                    println!("Space is already occupied!");
                    continue;
                }
                fill_board(m, Player1, &mut board);
                let victory_condition = check_for_win(&board);
                if victory_condition.0 == true {
                    println!("{:?} has won!", victory_condition.1);
                    break;
                }
            }
        }
        //Computer Turn
        if board_has_free_space(&board) {
            loop {
                let computer_move = (rand::thread_rng().gen_range(0, 3), rand::thread_rng().gen_range(0, 3));
                if move_is_illegal(computer_move, &board) {
                    continue;
                }
                fill_board(computer_move, Player2, &mut board);
                break;
            }
            let victory_condition = check_for_win(&board);
            if victory_condition.0 == true {
                println!("{:?} has won!", victory_condition.1);
                break;
            }
        }
    }
    print_board(&board);
}
