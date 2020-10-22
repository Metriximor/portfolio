var express = require("express");
var app = express();
var bodyParser = require("body-parser");

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

var port = process.env.PORT || 8080;

var mongoose = require("mongoose");
mongoose.connect("mongodb://127.0.0.1:27017/restapidb", { useNewUrlParser: true, useUnifiedTopology: true });

var db = mongoose.connection;
db.on("error", console.error.bind(console, 'connection error:'));

db.once("open", function () {
    console.log("DB connection alive");
});

var Bear = require("./app/models/bear");

var router = express.Router();

router.get('/', function (req, res) {
    res.json({ message: "hooray! welcome to our api" });
});

router.route("/bears")
    .post(function (req, res) {
        var bear = new Bear();
        bear.name = req.body.name;

        bear.save(function (err) {
            if (err) {
                res.send(err);
            }
            res.json({ message: "Bear created!" });
        });
    })
    .get(function (req, res) {
        Bear.find(function (err, bears) {
            if (err) {
                res.send(err);
            }
            res.json(bears);
        });
    });

router.route("/bears/:bear_id")
    .get(function (req, res) {
        Bear.findById(req.params.bear_id, function (err, bear) {
            if (err) {
                res.send(err);
            }
            res.json(bear);
        });
    })
    .put(function (req, res) {
        Bear.findById(req.params.bear_id, function (err, bear) {
            if (err) {
                res.send(err);
            }
            bear.name = req.body.name;
            bear.save(function (err) {
                if (err) {
                    res.send(err);
                }
                res.json({ message: "Bear updated!" });
            });
        });
    })
    .delete(function (req, res) {
        Bear.remove({ _id: req.params.bear_id }, function(err, bear) {
            if(err) {
                res.send(err);
            }
            res.send({ message : "Bear deleted!" });
        });
    });


router.use(function (req, res, next) {
    console.log("Something is happening");
    next();
})

app.use("/api", router);

app.listen(port);

console.log("Magic happens on port " + port);