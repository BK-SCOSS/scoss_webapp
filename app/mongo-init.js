db.createUser(
        {
            user: "scoss_admin",
            pwd: "scoss_admin",
            roles: [
                {
                    role: "readWrite",
                    db: "scoss"
                }
            ]
        }
);

db = db.getSiblingDB('scoss')

db.createCollection('user')

db.user.insert(
        {
            "user_id": "1602777811000",
            "username": "admin",
            "password": "pbkdf2:sha256:150000$Y2765SB3$7efdf6b00543f6bd21c73043f343ea5ba38f8ac1b40171380d8ccd3c69bdb39a",
            "role": 0
        }
);
