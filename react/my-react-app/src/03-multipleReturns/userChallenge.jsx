import { useState } from 'react'

const Challenge = () => {
  const [user, setUser] = useState(null)

  const login = () => {
    setUser({ name: 'vegan food truck' })
  }

  const logout = () => {
    setUser(null)
  }

  return (
    <div>
      {user ? (
        <div>
          <h2>Welcome back {user.name}</h2>
          <button type="button" onClick={logout}>
            Logout
          </button>
        </div>
      ) : (
        <div>
          <h2>Please login</h2>
          <button type="button" onClick={login}>
            Login
          </button>
        </div>
      )}
    </div>
  )
}

export default Challenge