// Write the following queries
// 1. All fields of games.
db.game.find({})

// 2. Games id.
db.game.find(
    {},
    { id: true }
)

// 3. Titles and descriptions.
db.game.find(
    {},
    { title: true, description: true }
)
// Il n'y a pas de description, donc seulement l'_id et le title s'affiche.

// 4. Titles.
db.game.find(
    {},
    { title: true }
)

// 5. Distinct titles.
db.game.distinct("title")

// 6. Years of release.*
db.game.find(
    {},
    { rel: true }
)

// 7. Games with a id less than 1000
db.game.find(
    { id: { $lt: 1000 } },
    {}
)

// 8. Games in 2000 and id greater than 48000.
db.game.find({
    $and: [
        { 
            rel: { 
                $gte: ISODate("2000-01-01T00:00:00.000Z"), 
                $lte: ISODate("2001-12-31T23:59:59.999Z") 
            } 
        }, 
        { id: { $gt: 48000 } }
    ]
}) 

// 9. Games titles with a id less than 1000.
db.game.find(
    { id: { $lt: 1000 } },
    { title: true }
)

// 10. Games sorted by title.
db.game.aggregate({ $sort: { title: -1 } })


// 11. Number of games per year.*
db.game.aggregate([ 
    { 
        $group: { 
            _id: {$year:"$rel"}, 
            count: { $count: {} } 
        } 
    }
])

// 12. Number of games per year with at least 3 games.*
db.game.aggregate([ 
    { 
        $group: { 
            _id: {$year:"$rel"}, 
            count: { $count: {} } 
        }
    },
    {
        $match: {
            count: {$gte:3}
        }
    }
])


// 13. Games which title ends by 2.*
db.game.find({ title: { $regex: "2$", $options: "i" } })
// Le "options:1" sert à rendre le regex insensible à la casse, mais dans ce cas qui ne précise aucun jeu, il ne sert à rien.
// Si on mettait "Call of duty 2$" avec le "option:1" les titres de jeux tout en maj, avec d'autre maj que le C serrais trouvé mais sans 
// le "options:1" il n'y aurait que les titres qui correspond exactement.


// 14. Games which id is between 1000 and 2000.
db.game.find(
    {
        $or: [
            { id: { $lte: 1000 } },
            { id: { $gte: 2000 } }
        ]
    }
)


// 1. Use DB TP
use TP

// 2. Insert in collection people 2 documents (id, name, age): (1, ’Alice’, 20), (1, ’Bob’, 35)
db.people.insertMany([
    { id: 1, name: "Alice", age: 20 },
    { id: 2, name: "Bob", age: 35 }
])


// 3. Display all databases
show databases


// 4. Display the current DB
db


// 5. Delete collection people
db.people.drop()

