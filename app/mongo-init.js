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
            "password": "pbkdf2:sha256:260000$xj3ueJYSRK2crTte$4e961d63ca19129c555a1259078db0c8fc158192d75ed09aec9e5888ba0ec1e6",
            "role": 0
        }
);
