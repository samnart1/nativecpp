import { useState, useEffect } from 'react'

const url = 'https://api.github.com/userss'

const FetchData = () => {
  const [users, setUsers] = useState([])

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch(url)
        const users = await response.json()
        setUsers(users)
        // console.log(users)
      } catch (error) {
        console.error(error)
      }
    }
    fetchData()
  }, [])
}

export default FetchData
